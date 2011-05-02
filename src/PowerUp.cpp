//
//  Obstacle.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "PowerUp.h"

namespace Micromachines {
    
	int PowerUp::RandomBeetween(int min, int max)
	{
		return (rand() % (max-min) + min);
	}
    
	PowerUp::PowerUp(std::string name) : cg::Entity(name){}
    
	PowerUp::~PowerUp(){}
    
	void PowerUp::init()
	{
		_winWidth = cg::Manager::instance()->getApp()->getWindow().width;
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		_position = cg::Vector3d(RandomBeetween(27, (_winWidth-27)), RandomBeetween(27, (_winHeight-27)), -400);
		_color = cg::Vector3d(0.9, 0.9, 0.9);
		_initialPos = _position;
		_direction = -1;
		_car = (Car*) cg::Registry::instance()->get("Car");
	}
    
	void PowerUp::draw()
	{
		
		glColor3d(_color[0], _color[1], _color[2]);
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
    
}
