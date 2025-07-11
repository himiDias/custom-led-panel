#ifndef SERVER_H
#define SERVER_H

#include "thread_safe_queue.h"

#include <string>

namespace desk_led{

	class Server{
		public:
		
		static void run_server(ThreadSafeQ<std::string>& shared_queue);
		
		void command_dispatcher(ThreadSafeQ<std::string>& server_comm_queue);
		
	};

}

#endif
