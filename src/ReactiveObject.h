//
//  ReactiveObject.h
//  cglib
//
//  Created by Inês on 4/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef REACTIVE_OBJECT_H
#define REACTIVE_OBJECT_H

#include "cg.h"
#include "Collidable.h"

namespace Micromachines {
	class PlayerManager;
	class Car;
	
	class ReactiveObject : public Collidable{
	private:
		cg::Vector3d _position, _initPos;
		PlayerManager* _pm;
		typedef std::vector<Car*>::iterator tplayersIterator;
		bool carNear(Car *car);
		cg::Vector2d _size;
		
	public:
		ReactiveObject(cg::Vector3d pos);
		~ReactiveObject();
		
		void init();
		void draw();
		void update(unsigned long elapsed_millis);
		cg::Vector3d getPosition();
		cg::Vector2d getSize();
	};
}

#endif