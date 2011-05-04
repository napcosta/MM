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
#include "Obstacle.h"
#include "ReactiveObject.h"
#include "PlayerManager.h"


namespace Micromachines {
	class CollisionManager : public cg::Entity, public cg::IUpdateListener {
	private:
		PlayerManager* _pm;
		typedef std::vector<Obstacle*>::iterator tObstacleIterator;
		typedef std::vector<ReactiveObject*>::iterator tReactObstaclesIterator;
		std::vector<Obstacle*> _obstacles;
		std::vector<ReactiveObject*> _reactObstacles;
		std::vector<Car*> _players;
		typedef std::vector<Car*>::iterator tplayersIterator;
		
	public:
		CollisionManager();
		~CollisionManager();
		void init();
		void update(unsigned long elapsed_millis);
		void setObstacles(std::vector<Obstacle*> obstacles);
		void setReactObstacles(std::vector<ReactiveObject*> obstacles);
	};
}

#endif
