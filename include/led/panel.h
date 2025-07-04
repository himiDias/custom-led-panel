#ifndef PANEL_H
#define PANEL_H

#include "thread_safe_queue.h"

#include "status_elem.h"
#include "time_elem.h"
#include "main_elem.h"

#include <string>

namespace desk_led{
	class Panel{
		public:
		
		static int run_panel(ThreadSafeQ<std::string>& shared_queue);
		
		private:
		
		static StatusElement status_e;
		static MainElement main_e;
		static TimeElement time_e;
		
		static void process_input(std::string input);
	};
	
}


#endif
