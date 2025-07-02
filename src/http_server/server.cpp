#include "crow.h"

#include "server.h"
#include "thread_safe_queue.h"

#include <iostream>
#include <string>

namespace desk_led{
	
	void Server::run_server(ThreadSafeQ<std::string>& shared_queue)
	{
		crow::SimpleApp app;
		
		std::cout << "Current workignn dir: " << std::filesystem::current_path() << std::endl;
		crow::mustache::set_global_base("src/http_server/templates");
	 
		
		CROW_ROUTE(app,"/")([](){
			auto page = crow::mustache::load("controller.html");
			return page.render();
		});
		
		CROW_ROUTE(app,"/static/<string>")([](const std::string& filename){
			std::ifstream in ("src/http_server/static/"+filename,std::ifstream::in);
			
			if (!in) return crow::response(404,".css not found");
			
			std::ostringstream contents;
			contents << in.rdbuf();
			in.close();
			crow::response res(contents.str());
			res.set_header("Content-type","text/css");
			return res;
		});
		
		CROW_ROUTE(app,"/button-pressed")([&shared_queue](const crow::request& req){
			auto query_params = crow::query_string(req.raw_url);
			//std::cout << "Request raw url: "<< req.raw_url<<std::endl;
			// gets id if id exists
			std::string id = query_params.get("id") ? query_params.get("id") : "NONE";
			
			std::cout << "Button pressed : " << id << std::endl;
			shared_queue.push(id);
			
			return crow::response(200,"Button " + id + "received");
		});	
		
		app.port(18080).multithreaded().run();

	}
	
}
