#include "crow.h"

#include <iostream>
#include <string>

int main()
{
	crow::SimpleApp app;
	
	std::cout << "Current workignn dir: " << std::filesystem::current_path() << std::endl;
	//crow::mustache::set_base("src/http_server");
 
	
	CROW_ROUTE(app,"/")([](){
		crow::mustache::set_base("src/http_server/templates");
		auto page = crow::mustache::load_text("controller.html");
		return page;
		//return crow::mustache::load("controller.html").render();
		//return "<html><body><p>TESTING IN LINE</p></body></html>";
	});
	
	app.port(18080).multithreaded().run();
}
