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
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {
	class ReactiveObject : public cg::Entity, public cg::IDrawListener, public cg::IUpdateListener{
	private:
		cg::Vector3d _position, _initPos;
		PlayerManager* _pm;
		typedef std::vector<Car*>::iterator tplayersIterator;
		
		bool carNear(Car *car);
		
	public:
		ReactiveObject(cg::Vector3d pos);
		~ReactiveObject();
		
		void init();
		void draw();
		void update(unsigned long elapsed_millis);
		cg::Vector3d getPosition();
	};
}

#endif