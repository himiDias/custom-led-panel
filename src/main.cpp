
#include "panel.h"
#include "server.h"
#include "thread_safe_queue.h"

#include <iostream>
#include <thread>
#include <string>

using namespace desk_led;

int main(){
	std::cout << "Testing main\n";
	
	ThreadSafeQ<std::string> panel_command_queue;
	ThreadSafeQ<std::string> server_command_queue;
	std::cout << "Shared queue created" <<std::endl;
	
	
	std::thread led_thread(&Panel::run_panel, std::ref(panel_command_queue), std::ref(server_command_queue));
	
	std::thread server_thread(&Server::run_server, std::ref(panel_command_queue));
	
	std::thread dispatcher_thread(&Server::command_dispatcher, std::ref(server_command_queue));
	
	
	led_thread.join();
	server_thread.join();
	return 0;
}
