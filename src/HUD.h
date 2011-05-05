#ifndef HUD_H
#define HUD_H

#include "cg.h"

namespace Micromachines {
	
	class PlayerManager;
	class Car;

	class HUD : public cg::IDrawOverlayListener,
		    public cg::Entity {
		
		private:
			PlayerManager* _pm;
			Car *_car;
			int _winWidth;
			int _winHeight;
			int _max;
			int _nitroRadius;
			    
			void drawLifeBar();
			void drawPowerUp();
			    
		public: 
			HUD();
			~HUD();
			void init();
			void drawOverlay();
			void drawString();
			void drawNitro();
			//void update(unsigned long elapsed_millis);
	
	};}
	
#endif
