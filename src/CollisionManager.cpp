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
		_players.push_back((Car*)cg::Registry::instance()->get("Player1"));
		_players.push_back((Car*)cg::Registry::instance()->get("Player2"));
		_obstacleManager = (ObstacleManager*)cg::Registry::instance()->get("OM");
	}
	
	void CollisionManager::update(unsigned long elapsed_millis)
	{
		bool frontCollision;
		
		for(tObstacleIterator i = _obstacleManager->getObstacles().begin(); i != _obstacleManager->getObstacles().end(); i++){
			cg::Vector2d size = cg::Vector2d(27, 18);
			
			for (int j = 0; j < _players.size(); j++) {
				if (_players[j]->getAppForce() >= 0)
					frontCollision = true;
				else
					frontCollision = false;
				if (_players[j]->isCollision((*i)->getPosition(), size)) {
					_players[j]->decreaseLife();
					if (frontCollision == true)
						_players[j]->setVelocity(-0.1);
					else if (frontCollision == false) {
						_players[j]->setVelocity(0.06);
						puts("here!");
					}
				}
			}
		}
		
		for(tReactObstaclesIterator i = _obstacleManager->getReactObstacles().begin(); i != _obstacleManager->getReactObstacles().end(); i++){
			cg::Vector2d size = cg::Vector2d(27, 18);
			for (int j = 0; j < _players.size(); j++) {
				if (_players[j]->getAppForce() >= 0)
					frontCollision = true;
				else
					frontCollision = false;
				if (_players[j]->isCollision((*i)->getPosition(), size)) {
					_players[j]->decreaseLife();
					if (frontCollision == true)
						_players[j]->setVelocity(-0.1);
					else if (frontCollision == false) {
						_players[j]->setVelocity(0.06);
						puts("here!");
					}
				}
			}
		}
	}
}
