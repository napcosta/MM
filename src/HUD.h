#ifndef HUD_H
#define HUD_H

#include "cg.h"
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {

	class HUD : public cg::IDrawOverlayListener,
		    public cg::Entity {
		
		private:
			PlayerManager* _pm;
			Car *_car;
			int _winWidth;
			int _winHeight;
			int _max;
			    
			void drawLifeBar();
			    
		public: 
			HUD();
			~HUD();
			void init();
			void drawOverlay();
			void drawString();
			void update(unsigned long elapsed_millis);
	
	};}
	
#endif
