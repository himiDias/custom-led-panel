#ifndef PANEL_H
#define PANEL_H

#include "thread_safe_queue.h"

#include "status_elem.h"
#include "time_elem.h"
#include "main_elem.h"

#include "paint_elem.h"

#include <string>
#include <functional>

namespace desk_led{
	
	enum SceneState{
		SCENE_MENU,
		SCENE_PAINT,
		SCENE_GAMES,
		SCENE_SS
		
	};
	
	class Panel{
		public:
		
		static int run_panel(ThreadSafeQ<std::string>& led_cmds_queue,ThreadSafeQ<std::string>& server_cmds_queue);
		
		private:
		
		static StatusElement status_e;
		static MainElement main_e;
		static TimeElement time_e;
		
		static PaintElement paint_e;
		
		static SceneState scene;
		
		static std::function<void()> process_input(std::string input,rgb_matrix::FrameCanvas*& canvas);
	};
	
}


#endif
