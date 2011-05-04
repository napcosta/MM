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
	}
	
	void CollisionManager::update(unsigned long elapsed_millis)
	{
		bool frontCollision;
		
		for(tObstacleIterator i = _obstacles.begin(); i != _obstacles.end(); i++){
		//	std::cout << (*i)->getId() << std::endl;
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
				}
			}
		
		}
		for(tReactObstaclesIterator i = _reactObstacles.begin(); i != _reactObstacles.end(); i++){
			cg::Vector2d size = cg::Vector2d(27, 18);
			//for (int j = 0; j < _players.size(); j++) {
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
				}
			}
		}
		
		for (tPowerUpIterator i = _powerUp.begin(); i != _powerUp.end(); i++) {
			cg::Vector2d size = cg::Vector2d(0, 0);
			//std::cout << (*i)->getPosition() << std::endl;
			if (_car->isCollision((*i)->getPosition(), size)) {
				puts("POWERUP");
			}
		}
	}
	
	void CollisionManager::setObstacles(std::vector<Obstacle*> obstacles)
	{
		_obstacles = obstacles;
	}
	
	void CollisionManager::setReactObstacles(std::vector<ReactiveObject*> obstacles)
	{
		_reactObstacles = obstacles;
	}
	
	void CollisionManager::setPowerUps(std::vector<PowerUp*> powerUp)
	{
		_powerUp = powerUp;
	}
}
