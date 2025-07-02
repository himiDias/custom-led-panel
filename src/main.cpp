
#include "panel.h"
#include "server.h"

#include <iostream>
#include <thread>

using namespace desk_led;

int main(){
	std::cout << "Testing main\n";
	
	
	std::thread led_thread(&Panel::run_panel);
	
	std::thread server_thread(&Server::run_server);
	
	
	led_thread.join();
	server_thread.join();
	return 0;
}
