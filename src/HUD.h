#ifndef HUD_H
#define HUD_H

#include "cg.h"


namespace Micromachines {

	class HUD : public cg::IDrawOverlayListener,
		    public cg::Entity {
		
		public: 
			HUD();
			~HUD();
			void init();
			void drawOverlay();
			void drawString();
			void update(unsigned long elapsed_millis);
	
	};}
	
#endif
