

#include <bgcc.h>
#include "AgentProxy.h"
#include "WS_ApServer.h"
using namespace std;

int main(int argc, char **argv)
{
// #ifdef _WIN32
//     HWND hwnd;
//     hwnd = FindWindow("ConsoleWindowClass", NULL); //找到当前窗口句柄
// 
//     if (hwnd)
//     {
//         ShowWindow(hwnd, SW_HIDE); //控制窗口不可见
//     }
// 
// #endif
// 
//     AgentProxy *agentPrx = AgentProxy::Instance();
// 
//     if (!agentPrx->Init())
//     {
//         BGCC_FATAL("ap", "AgentPrx Init Failed.");
//         Exit();
//     }

//     wsServer echo_server;
// 
//     try
//     {
//         // Set logging settings
//         echo_server.set_access_channels(websocketpp::log::alevel::all);
//         echo_server.clear_access_channels(websocketpp::log::alevel::frame_payload);
// 
//         // Initialize Asio
//         echo_server.init_asio();
// 
//         // Register our message handler
//         echo_server.set_message_handler(boost::bind(&on_message, &echo_server, ::_1, ::_2));
//         echo_server.set_open_handler(bind(&on_open, &echo_server, ::_1));
//         echo_server.set_close_handler(bind(&on_close, &echo_server, ::_1));
// 
//         // Listen on port 9002
//         echo_server.listen(9002);
// 
//         // Start the server accept loop
//         echo_server.start_accept();
// 
//         // Start the ASIO io_service run loop
//         echo_server.run();
//     }
//     catch (websocketpp::exception const &e)
//     {
//         BGCC_WARN("ap", "init websocket except because: %s", e.what());
//     }
//     catch (...)
//     {
//         BGCC_WARN("ap", "init websocket other exception because: ");
//     }
 //   Exit();

	WSapserver ws_apserver;
	AgentProxy *agentPrx = AgentProxy::Instance();
	if (!agentPrx->Init())
	{
		BGCC_FATAL("ap", "AgentPrx Init Failed.");
		//Exit();
	}
	ws_apserver.InitApServer("192.168.2.100",8071,10);
	ws_apserver.startServer();

	sleep(10000);
	return 0;


}
