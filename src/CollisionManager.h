//
//  CollisionManager.h
//  cglib
//
//  Created by Inês on 4/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "cg.h"
#include "Car.h"
#include "PowerUp.h"
#include "Obstacle.h"
#include "ReactiveObject.h"


namespace Micromachines {
	class CollisionManager : public cg::Entity, public cg::IUpdateListener {
	private:
	//	std::vector<Car*> _players;
		Car* _car;
		//ObstacleManager* _obstacleManager;
		typedef std::vector<Obstacle*>::iterator tObstacleIterator;
		typedef std::vector<ReactiveObject*>::iterator tReactObstaclesIterator;
		typedef std::vector<PowerUp*>::iterator tPowerUpIterator;
		std::vector<Obstacle*> _obstacles;
		std::vector<ReactiveObject*> _reactObstacles;
		std::vector<PowerUp*> _powerUp;
		
	public:
		CollisionManager();
		~CollisionManager();
		void init();
		void update(unsigned long elapsed_millis);
		void setObstacles(std::vector<Obstacle*> obstacles);
		void setReactObstacles(std::vector<ReactiveObject*> obstacles);
		void setPowerUps(std::vector<PowerUp*> powerUp);
	};
}

#endif
