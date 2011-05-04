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
#include "PlayerManager.h"


namespace Micromachines {
	class CollisionManager : public cg::Entity, public cg::IUpdateListener {
	private:
		PlayerManager* _pm;
		typedef std::vector<Collidable*>::iterator tCollidableIterator;
		typedef std::vector<PowerUp*>::iterator tPowerUpIterator;
		std::vector<Collidable*> _obstacles;
		std::vector<Car*> _players;
		typedef std::vector<Car*>::iterator tplayersIterator;
		std::vector<PowerUp*> _powerUp;
		
	public:
		CollisionManager();
		~CollisionManager();
		void init();
		void update(unsigned long elapsed_millis);
		void setObstacles(std::vector<Collidable*> obstacles);
		void setPowerUps(std::vector<PowerUp*> powerUp);
	};
}

#endif
