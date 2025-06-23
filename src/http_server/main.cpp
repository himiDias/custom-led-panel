#include "crow.h"

int main()
{
	crow::SimpleApp app;
	
	CROW_ROUTE(app,"/")([](){
		auto page = crow::mustache::load_text("/src/http_server/controller.html");
		return page;
	});
	
	app.port(18080).multithreaded().run();
}
