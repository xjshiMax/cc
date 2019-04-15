/***************************************************************************
 *
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$
 *
 **************************************************************************/



/**
 * @file callback_recv_impl.h
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 11:31:37
 * @version 1.0.0
 * @brief
 *
 **/


#ifndef  __CALLBACK_RECV_IMPL_H_
#define  __CALLBACK_RECV_IMPL_H_

#include "output-cpp/callback.h"

class callback_recv_impl_t : public demo::CallbackRecver {
public:
    virtual demo::CallbackResult Callback(
            int32_t val,
            const std::map<std::string, std::string>& ctx);
};















#endif  //__CALLBACK_RECV_IMPL_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
