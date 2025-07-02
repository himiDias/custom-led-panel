#ifndef PANEL_H
#define PANEL_H

#include "thread_safe_queue.h"

#include <string>

namespace desk_led{
	class Panel{
		public:
		
		static int run_panel(ThreadSafeQ<std::string>& shared_queue);
	};
	
}


#endif
