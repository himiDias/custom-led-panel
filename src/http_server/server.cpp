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
	 
		// User end pages
		/*
		CROW_ROUTE(app,"/")([](){
			auto page = crow::mustache::load("controller.html");
			return page.render();
		});
			
		
		CROW_ROUTE(app,"/settings")([](){
			auto page = crow::mustache::load("settings.html");
			return page.render();
		});*/
		
		CROW_WEBSOCKET_ROUTE(app,"/ws")
			.onopen([&](crow::websocket::connection& conn){
				std::cout << "Websocket : CONNECTED" << std::endl;
			})
			
			.onclose([&](crow::websocket::connection& conn, const std::string& reason, uint16_t with_status_code){
				std::cout << "Websocket : CONNECTION CLOSED : " << reason << std::endl;
			})
			
			.onmessage([&](crow::websocket::connection& conn, const std::string& message, bool is_binary){
				std::cout << "Websocket : CLIENT MESSAGE : " << message << std::endl;
				shared_queue.push(message);
			})
			
			.onerror([&](crow::websocket::connection& conn, const std::string& error_message){
				std::cerr << "Websocket : ERROR OCCURRED : " << error_message << std::endl;
			});
		
		
		// Intermediate pages
		/*COMMENTED FOR TESTING, USING REACT INSTEAD, 
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
		*/
		app.port(18080).multithreaded().run();

	}
	
}
