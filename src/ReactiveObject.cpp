//
//  ReactiveObject.cpp
//  cglib
//
//  Created by Inês on 4/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ReactiveObject.h"

namespace Micromachines {
	
	ReactiveObject::ReactiveObject(cg::Vector3d pos) : cg::Entity("REACTIVE_OBJ")
	{
		_position = pos;
	}
	
	ReactiveObject::~ReactiveObject()
	{}
	
	void ReactiveObject::init()
	{
		_car = (Car*)cg::Registry::instance()->get("Car");
		_initPos = _position;
	}
	
	void ReactiveObject::draw()
	{
		glColor3d(1, 1, 0);
		glBegin(GL_QUADS);
		//top
		glVertex3d(_position[0]-27, _position[1]+18, -400);       
		glVertex3d(_position[0]-27, _position[1]-18, -400);       
		glVertex3d(_position[0]+27, _position[1]-18, -400);       
		glVertex3d(_position[0]+27, _position[1]+18, -400);
		
		//bottom
		glVertex3d(_position[0]-27, _position[1]+18, -395);       
		glVertex3d(_position[0]-27, _position[1]-18, -395);       
		glVertex3d(_position[0]+27, _position[1]-18, -395);       
		glVertex3d(_position[0]+27, _position[1]+18, -395);
		
		//side1
		glVertex3d(_position[0]-27, _position[1]-18, -400);
		glVertex3d(_position[0]+27, _position[1]-18, -400);
		glVertex3d(_position[0]+27, _position[1]-18, -395);
		glVertex3d(_position[0]-27, _position[1]-18, -395);
		
		//side2
		glVertex3d(_position[0]+27, _position[1]-18, -400);
		glVertex3d(_position[0]+27, _position[1]+18, -400);
		glVertex3d(_position[0]+27, _position[1]+18, -395);
		glVertex3d(_position[0]+27, _position[1]-18, -395);
		
		//side3
		glVertex3d(_position[0]-27, _position[1]+18, -400);
		glVertex3d(_position[0]+27, _position[1]+18, -400);
		glVertex3d(_position[0]+27, _position[1]+18, -395);
		glVertex3d(_position[0]-27, _position[1]+18, -395);
		
		//side4
		glVertex3d(_position[0]-27, _position[1]-18, -400);
		glVertex3d(_position[0]-27, _position[1]+18, -400);
		glVertex3d(_position[0]-27, _position[1]+18, -395);
		glVertex3d(_position[0]-27, _position[1]-18, -395);
		
		glEnd();
	}
	
	bool ReactiveObject::carNear()
	{
		cg::Vector3d carPos = _car->getPosition();
		
		return (carPos[0] > _position[0]-50 && carPos[0] < _position[0]+50 && carPos[1] > _position[1]-50 && carPos[1] < _position[1]+50);
	}
	
	void ReactiveObject::update(unsigned long elapsed_millis)
	{
		if(carNear()){
			if(_position[0] <= _initPos[0]+20 && _position[0] >= _initPos[0])
				_position[0] = _position[0]+5;
		}
		else if (_position[0] > _initPos[0])
			_position[0] = _position[0]-5;
	
/*		bool frontCollision;
		
		cg::Vector2d size = cg::Vector2d(27, 18);
		if (_car->getAppForce() >= 0)
			frontCollision = true;
		else
			frontCollision = false;
		if (_car->isCollision(_position, size)) {
			_car->decreaseLife();
			if (frontCollision == true)
				_car->setVelocity(-0.1);
			else if (frontCollision == false) {
				_car->setVelocity(0.06);
				puts("here");
			}
		}*/	
	}
	
	cg::Vector3d ReactiveObject::getPosition()
	{
		std::cout << "reactOb " << _position << std::endl;
		return _position;
	}
}
