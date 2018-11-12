/*
 * Copyright 2002-2014 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      CC/LICENSE
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <bgcc.h>
#include "AgentProxy.h"

using namespace std;

#include <websocketpp/config/asio_no_tls.hpp>

#include <websocketpp/server.hpp>

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

// pull out the type of messages sent by our config
typedef websocketpp::server<websocketpp::config::asio> wsServer;
typedef wsServer::message_ptr message_ptr;

// Define a callback to handle incoming messages
void on_open(wsServer* s, websocketpp::connection_hdl hdl)
{
    BGCC_TRACE("ap", "on_open called with hdl:%d", hdl.lock().get() );

}

void on_close(wsServer* s, websocketpp::connection_hdl hdl)
{
    BGCC_TRACE("ap", "on_close called with hdl:%d", hdl.lock().get() );

}
void on_message(wsServer *s, websocketpp::connection_hdl hdl, message_ptr msg)
{
    BGCC_TRACE("ap", "recv message:%s.", msg->get_payload().c_str());
    printf("recv message:%s.\n",msg->get_payload().c_str());
    // check for a special command to instruct the server to stop listening so
    // it can be cleanly exited.
    if (msg->get_payload() == "stop-listening")
    {
        s->stop_listening();
        return;
    }
    try
    {
        s->send(hdl, msg->get_payload(), msg->get_opcode());
    }
    catch (websocketpp::exception const &e)
    {
        BGCC_WARN("ap", "Echo failed because: %s", e.what());
    }

}

#define Exit()               \
    {                        \
        agentPrx->Destroy(); \
        return 0;            \
    }

int main(int argc, char **argv)
{
#ifdef _WIN32
    HWND hwnd;
    hwnd = FindWindow("ConsoleWindowClass", NULL); //找到当前窗口句柄

    if (hwnd)
    {
        ShowWindow(hwnd, SW_HIDE); //控制窗口不可见
    }

#endif

    AgentProxy *agentPrx = AgentProxy::Instance();

    if (!agentPrx->Init())
    {
        BGCC_FATAL("ap", "AgentPrx Init Failed.");
        Exit();
    }

    wsServer echo_server;

    try
    {
        // Set logging settings
        echo_server.set_access_channels(websocketpp::log::alevel::all);
        echo_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        echo_server.init_asio();

        // Register our message handler
        echo_server.set_message_handler(boost::bind(&on_message, &echo_server, ::_1, ::_2));
        echo_server.set_open_handler(bind(&on_open, &echo_server, ::_1));
        echo_server.set_close_handler(bind(&on_close, &echo_server, ::_1));

        // Listen on port 9002
        echo_server.listen(9002);

        // Start the server accept loop
        echo_server.start_accept();

        // Start the ASIO io_service run loop
        echo_server.run();
    }
    catch (websocketpp::exception const &e)
    {
        BGCC_WARN("ap", "init websocket except because: %s", e.what());
    }
    catch (...)
    {
        BGCC_WARN("ap", "init websocket other exception because: ");
    }
    Exit();


}
