//
//  ObstacleManager.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "PowerUpManager.h"

namespace Micromachines {
    
	PowerUpManager::PowerUpManager(std::string id) : cg::Group(id) 
	{
	}
	PowerUpManager::~PowerUpManager() 
	{
	}
	void PowerUpManager::createEntities() 
	{
		int nPowerUps = cg::Properties::instance()->getInt("N_POWERUPS");
		srand((unsigned)time(0));
		for(int i = 0; i < nPowerUps; i++) {
			std::ostringstream os;
			os << "PowerUp" << i;
			add(new PowerUp(os.str()));
		}
	}
}
