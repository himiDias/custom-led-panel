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
	});
	
	CROW_ROUTE(app,"/button-pressed")([](const crow::request& req){
		auto query_params = crow::query_string(req.raw_url);
		//std::cout << "Request raw url: "<< req.raw_url<<std::endl;
		// gets id if id exists
		std::string id = query_params.get("id") ? query_params.get("id") : "NONE";
		
		std::cout << "Button pressed : " << id << std::endl;
		
		return crow::response(200,"Button " + id + "received");
	});	
	
	app.port(18080).multithreaded().run();
}
