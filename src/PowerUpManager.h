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
                            public cg::GroupDraw {
                            
        private:
        	CollisionManager* _cm;
        	std::vector<PowerUp*> _powerUp;
	protected:
		void createEntities();
                                
	public:
		PowerUpManager(std::string id);
		~PowerUpManager();
		std::vector<PowerUp*> getPowerUp();
                                
	};
    
}

#endif
