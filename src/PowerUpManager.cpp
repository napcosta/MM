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
		_cm = (CollisionManager*)cg::Registry::instance()->get("COLLISION_MANAGER");
		srand((unsigned)time(0));
		for(int i = 0; i < nPowerUps; i++) {
			cg::Vector3d pos = cg::Vector3d(-50,-125+i*20, -400); // the coordinates of the powerups
			std::ostringstream os;
			os << "PowerUp" << i;
			PowerUp *pu = new PowerUp(os.str(), pos);
			pu->init();
			_powerUp.push_back(pu);

		}
		_cm->setPowerUps(_powerUp);
	}
	
	void PowerUpManager::draw()
	{
		for(tPowerUpIterator i = _powerUp.begin(); i != _powerUp.end(); i++) {
			(*i)->draw();
		}
	}
	void PowerUpManager::update(unsigned long elapsed_millis)
	{
		for(tPowerUpIterator i = _powerUp.begin(); i != _powerUp.end(); i++) {
			(*i)->update(elapsed_millis);
		}
	}
}
