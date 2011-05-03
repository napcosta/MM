#ifndef POWERUP_MANAGER_H
#define POWERUP_MANAGER_H

#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cg.h"
#include "PowerUp.h"

namespace Micromachines {
    
	class PowerUpManager : public cg::Group,
                            public cg::GroupDraw {
	protected:
		void createEntities();
                                
	public:
		PowerUpManager(std::string id);
		~PowerUpManager();
                                
	};
    
}

#endif
