//
//  CollisionManager.cpp
//  cglib
//
//  Created by Inês on 4/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "CollisionManager.h"
#include "Car.h"
#include "PowerUp.h"
#include "Obstacle.h"
#include "ReactiveObject.h"
#include "PlayerManager.h"

namespace Micromachines{
	
	CollisionManager::CollisionManager() : cg::Entity("COLLISION_MANAGER")
	{}
	
	CollisionManager::~CollisionManager()
	{}
	
	void CollisionManager::init()
	{	
		_pm = (PlayerManager*)cg::Registry::instance()->get("PlayerManager");
	}
	
	void CollisionManager::update(unsigned long elapsed_millis)
	{
		_players = _pm->getPlayers();
		bool frontCollision;
		
		for (tplayersIterator j = _players.begin(); j != _players.end(); j++) {
			
			for(tCollidableIterator i = _obstacles.begin(); i != _obstacles.end(); i++){
				if (_pm->hasTwoPlayers() || !(*j)->getId().compare("Car2")) {
					if ((*j)->getAppForce() >= 0)
						frontCollision = true;
					else
						frontCollision = false;
					if (((*j) != (*i)) && ((*j)->isCollision((*i)->getPosition(), (*i)->getSize()))) {
						(*j)->decreaseLife();
						if (frontCollision == true)
							(*j)->setVelocity(-0.1);
						else if (frontCollision == false) {
							(*j)->setVelocity(0.06);
						}
					}
				}
				
			}
			
			for (tPowerUpIterator i = _powerUp.begin(); i != _powerUp.end(); i++) {
				if ((*j)->isCollision((*i)->getPosition(), (*i)->getSize())) {
					(*j)->incPowerUp();
					puts("POWERUP");
				}
			}
		}
	}
	
	void CollisionManager::setObstacles(std::vector<Collidable*> obstacles)
	{
		for (tCollidableIterator i = obstacles.begin(); i != obstacles.end(); i++)
			_obstacles.push_back(*i);
	}
	
	void CollisionManager::setPowerUps(std::vector<PowerUp*> powerUp)
	{
		for (tPowerUpIterator i = powerUp.begin(); i != powerUp.end(); i++) 
			_powerUp.push_back(*i);
	}
}