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
#include "ObstacleManager.h"

namespace Micromachines {
	class CollisionManager : public cg::Entity, public cg::IUpdateListener {
	private:
		std::vector<Car*> _players;
		ObstacleManager* _obstacleManager;
		typedef std::vector<Obstacle*>::iterator tObstacleIterator;
		typedef std::vector<ReactiveObject*>::iterator tReactObstaclesIterator;
		
	public:
		CollisionManager();
		~CollisionManager();
		void init();
		void update(unsigned long elapsed_millis);
	};
}

#endif