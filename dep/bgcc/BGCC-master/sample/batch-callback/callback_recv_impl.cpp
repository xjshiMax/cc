/***************************************************************************
 * 
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file callback_recv_impl.cpp
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 11:33:15
 * @version 1.0.0 
 * @brief 
 *  
 **/

#include "callback_recv_impl.h"

extern std::map<std::string,demo::CallbackRecverProxy > g_proxys;
extern bgcc::Mutex g_mutex;

demo::CallbackResult callback_recv_impl_t::Callback(
            int32_t num,
            const std::map<std::string, std::string>& ctx){

	std::map<std::string, std::string>::const_iterator it= ctx.find("ProxyName");

	std::string name;
	if(it!=ctx.end()){
		name=it->second;
	}

	BGCC_TRACE("client","prx %s recv callback %d", name.c_str(), num);

	return demo::CallbackResult(demo::CallbackResult::R_SUCC);
}




















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
