//
//  CollisionManager.cpp
//  cglib
//
//  Created by Inês on 4/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "CollisionManager.h"

namespace Micromachines{
	
	CollisionManager::CollisionManager() : cg::Entity("COLLISION_MANAGER")
	{}
	
	CollisionManager::~CollisionManager()
	{}
	
	void CollisionManager::init()
	{
		_car = (Car*)cg::Registry::instance()->get("Car");
		_obstacleManager = (ObstacleManager*)cg::Registry::instance()->get("ObstacleManager");
	}
	
	void CollisionManager::update(unsigned long elapsed_millis)
	{
		bool frontCollision;
		
		for(tObstacleIterator i = _obstacleManager->getObstacles().begin(); i != _obstacleManager->getObstacles().end(); i++){
			cg::Vector2d size = cg::Vector2d(27, 18);
			if (_car->getAppForce() >= 0)
				frontCollision = true;
			else
				frontCollision = false;
			if (_car->isCollision((*i)->getPosition(), size)) {
				_car->decreaseLife();
				if (frontCollision == true)
					_car->setVelocity(-0.1);
				else if (frontCollision == false) {
					_car->setVelocity(0.06);
					puts("here!");
				}
			}
		}
		
		for(tReactObstaclesIterator i = _obstacleManager->getReactObstacles().begin(); i != _obstacleManager->getReactObstacles().end(); i++){
			cg::Vector2d size = cg::Vector2d(27, 18);
			if (_car->getAppForce() >= 0)
				frontCollision = true;
			else
				frontCollision = false;
			if (_car->isCollision((*i)->getPosition(), size)) {
				_car->decreaseLife();
				if (frontCollision == true)
					_car->setVelocity(-0.1);
				else if (frontCollision == false) {
					_car->setVelocity(0.06);
					puts("here!");
				}
			}
		}
	}
}
