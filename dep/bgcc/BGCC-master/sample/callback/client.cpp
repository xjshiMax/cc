/***************************************************************************
 *
 * Copyright (c) 2012 Baidu.com, Inc. All Rights Reserved
 * $Id$
 *
 **************************************************************************/



/**
 * @file client.cpp
 * @author chenyuzhen(chenyuzhen@baidu.com)
 * @date 2012/11/13 16:21:10
 * @version 1.0.0
 * @brief
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bgcc.h>

#include "output-cpp/callback.h"
#include "callback_recv_impl.h"

using namespace bgcc;

#define SERVER_PORT 8321
#define SERVER_IP "127.0.0.1"

void menu();

int main(int /*argc*/, char ** /*argv*/)
{
    log_open("client.conf");

    SharedPointer<IProcessor> proc_recv(
            new demo::CallbackRecverProcessor(
                    SharedPointer<callback_recv_impl_t> (new callback_recv_impl_t)));

    ServiceManager mgr;
    mgr.add_service(proc_recv);
    ServerInfo si(SERVER_IP, SERVER_PORT);

	for (int i = 0; i < 1000; ++i) {
		demo::CallbackSenderProxy* prx = new demo::CallbackSenderProxy(si, 10, &mgr, 0);
		prx->set_property(bgcc::BaseProxy::PROXY_HB_TIMEOUT, 5000);
		prx->AddClient();
	}

   // menu();

   // char c;
   // do {
   //     try {
   //         std::cout << "==> ";
   //         std::cin >> c;
   //         if (c == 'a') {
   //             prx.AddClient();
   //         } else if (c == 'd') {
   //             prx.DelClient();
   //         } else if (c == 'x') {
   //         } else if (c == '?') {
   //             menu();
   //         } else {
   //             std::cout << "unknown command `" << c << "'" << std::endl;
   //             menu();
   //         }
   //     } catch (const std::exception& ex) {
   //         BGCC_FATAL("client", "ex:%s", ex.what());
   //     }
   // } while (std::cin.good() && c != 'x');

	while (1) {
		bgcc::TimeUtil::safe_sleep_s(1);
	}

	return 0;
}

void menu()
{
    std::cout <<
              "Usage:\n"
              "a: Add Client\n"
              "d: Del Client\n"
              "x: Exit\n"
              "?: Help\n";
}


/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
