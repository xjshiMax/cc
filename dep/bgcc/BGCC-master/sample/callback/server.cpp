/***************************************************************************
 *
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$
 *
 **************************************************************************/



/**
 * @file server.cpp
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 11:23:35
 * @version 1.0.0
 * @brief
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgcc.h>

#include "output-cpp/callback.h"
#include "callback_send_impl.h"

using namespace bgcc;

#define LISTEN_PORT 8321
#define POOL_SIZE 10

int main(int /*argc*/, char ** /*argv*/)
{
    log_open("server.conf");

    SharedPointer<Thread> thrd(new Thread(SharedPointer<Runnable>(new callback_send_thrd_t)));
    thrd->start();

    SharedPointer<IProcessor> proc_send(
            new demo::CallbackSenderProcessor(
                    SharedPointer<callback_send_impl_t> (new callback_send_impl_t)));
    ServiceManager mgr;
    mgr.add_service(proc_send);

    ThreadPool pool;
    pool.init(POOL_SIZE);

    Server server(&mgr, &pool, LISTEN_PORT);
    server.serve();

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
