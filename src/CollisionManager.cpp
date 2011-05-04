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
		//_car = (Car*)cg::Registry::instance()->get("Car");
		//_players.push_back((Car*)cg::Registry::instance()->get("Car"));
	//	_players.push_back((Car*)cg::Registry::instance()->get("Player2"));
	//	_obstacleManager = (ObstacleManager*)cg::Registry::instance()->get("OM");
	//	_obstacles = _obstacleManager->getObstacles();
	}
	
	void CollisionManager::update(unsigned long elapsed_millis)
	{
	/*	bool frontCollision;
		
		//std::vector<Entity*>::iterator iend = _obstacleManager->end();
		
		for(tObstacleIterator i = _obstacles.begin(); i != _obstacles.end(); i++){
		puts("LALALALALALALA");
			std::cout << (*i)->getId() << std::endl;
			cg::Vector2d size = cg::Vector2d(27, 18);
			
	//		for (int j = 0; j < _players.size(); j++) {
				if (_car->getAppForce() >= 0)
					frontCollision = true;
				else
					frontCollision = false;
				if (_car->isCollision((*i)->getPosition(), size)) {
				printf("baTI\n");
					_car->decreaseLife();
					if (frontCollision == true)
						_car->setVelocity(-0.1);
					else if (frontCollision == false) {
						_car->setVelocity(0.06);
						puts("here!");
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
				printf("ola\n");
					_car->decreaseLife();
					if (frontCollision == true)
						_car->setVelocity(-0.1);
					else if (frontCollision == false) {
						_car->setVelocity(0.06);
						puts("here!");
					}
				}
			
		}*/
	}
	
	void CollisionManager::setObstacles(std::vector<Obstacle*> obstacles)
	{
		_obstacles = obstacles;
	}
	
	void CollisionManager::setReactObstacles(std::vector<ReactiveObject*> obstacles)
	{
		_reactObstacles = obstacles;
	}
}
