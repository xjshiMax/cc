/***************************************************************************
 *
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$
 *
 **************************************************************************/



/**
 * @file callback_send_impl.cpp
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 11:27:56
 * @version 1.0.0
 * @brief
 *
 **/

#include <bgcc.h>
#include "callback_send_impl.h"

std::map<std::string, demo::SSLCallbackRecverProxy*> g_proxys;
bgcc::Mutex g_mutex;

demo::CallbackResult callback_send_impl_t::AddClient(
        const std::map<std::string, std::string>& ctx)
{
    std::map<std::string, std::string>::const_iterator it = ctx.find("ProxyName");

    if (it == ctx.end()) {
        BGCC_WARN("server", "not find proxyname in contex");
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    bgcc::Guard<bgcc::Mutex> lock(&g_mutex);
    if (!lock.is_locked()) {
        BGCC_WARN("server", "lock failed");
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    if (g_proxys.find(it->second) != g_proxys.end()) {
        BGCC_WARN("server", "proxy name:%s is exists", it->second.c_str());
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    demo::SSLCallbackRecverProxy * px = new(std::nothrow) demo::SSLCallbackRecverProxy(it->second, 1);

    if (!px) {
        BGCC_WARN("server", "create proxy(%s) failed", it->second.c_str());
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    g_proxys.insert(std::pair<std::string, demo::SSLCallbackRecverProxy*>(it->second.c_str() , px));


    BGCC_TRACE("server", "Add Client %s SUCC", it->second.c_str());
    return demo::CallbackResult(demo::CallbackResult::R_SUCC);
}

demo::CallbackResult callback_send_impl_t::DelClient(
        const std::map<std::string, std::string>& ctx)
{

    std::map<std::string, std::string>::const_iterator it = ctx.find("ProxyName");

    if (it == ctx.end()) {
        BGCC_WARN("server", "not find proxyname in contex");
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    bgcc::Guard<bgcc::Mutex> lock(&g_mutex);
    if (!lock.is_locked()) {
        BGCC_WARN("server", "lock failed");
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    if (g_proxys.find(it->second) == g_proxys.end()) {
        BGCC_WARN("server", "proxy name:%s is not exists", it->second.c_str());
        return demo::CallbackResult(demo::CallbackResult::R_FAIL);
    }

    demo::SSLCallbackRecverProxy* proxy = g_proxys[it->second];

    g_proxys.erase(it->second);

    delete proxy;
    proxy = NULL;

    BGCC_TRACE("server", "Del Client %s SUCC", it->second.c_str());
    return demo::CallbackResult(demo::CallbackResult::R_SUCC);
}

int32_t callback_send_thrd_t::operator()(const bool * isstopped, void* /*arg*/)
{
    int32_t count = 0;
    while (!(*isstopped)) {
        bgcc::TimeUtil::safe_sleep_s(1);
        {
            bgcc::Guard<bgcc::Mutex> lock(&g_mutex);
            if (!lock.is_locked()) {
                continue;
            }

            if (!g_proxys.size()) {
                continue;
            }
            ++count;
            for (std::map<std::string, demo::SSLCallbackRecverProxy* >::iterator it = g_proxys.begin();
                    it != g_proxys.end();) {
                BGCC_TRACE("server", "callback begin");
                it->second->Callback(count);
                BGCC_TRACE("server", "callback end{%d} {%s}", it->second->get_errno(), strerror(it->second->get_errno()));
                if (it->second->get_errno()) {
                    delete it->second;
                    g_proxys.erase(it++);
				} else {
					++it;
				}
            }
        }
    }

    return 0;
}


/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
