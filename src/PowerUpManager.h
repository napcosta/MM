#ifndef POWERUP_MANAGER_H
#define POWERUP_MANAGER_H

#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cg.h"
#include "PowerUp.h"
#include "CollisionManager.h"

namespace Micromachines {
    
	class PowerUpManager : public cg::Group,
                            public cg::GroupDraw,
                            public cg::GroupUpdate {
                            
        private:
        	CollisionManager* _cm;
        	std::vector<PowerUp*> _powerUp;
        	typedef std::vector<PowerUp*>::iterator tPowerUpIterator;
	protected:
		void createEntities();
                                
	public:
		PowerUpManager(std::string id);
		~PowerUpManager();
		std::vector<PowerUp*> getPowerUp();
		void draw();
		void update(unsigned long elapsed_millis);
                                
	};
    
}

#endif
