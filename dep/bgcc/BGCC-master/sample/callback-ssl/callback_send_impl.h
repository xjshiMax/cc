/***************************************************************************
 *
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$
 *
 **************************************************************************/



/**
 * @file callback_send_impl.h
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 11:25:46
 * @version 1.0.0
 * @brief
 *
 **/


#ifndef  __CALLBACK_SEND_IMPL_H_
#define  __CALLBACK_SEND_IMPL_H_

#include "output-cpp/callback.h"

extern std::map<std::string, demo::SSLCallbackRecverProxy*> g_proxys;
extern bgcc::Mutex g_mutex;

class callback_send_impl_t : public demo::CallbackSender {
public:
    virtual demo::CallbackResult AddClient(
            const std::map<std::string, std::string>& ctx);

    virtual demo::CallbackResult DelClient(
            const std::map<std::string, std::string>& ctx);
};


class callback_send_thrd_t : public bgcc::Runnable {
    virtual int32_t operator()(const bool* isstopped, void* arg);
};














#endif  //__CALLBACK_SEND_IMPL_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
