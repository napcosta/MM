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
    
	PowerUp::PowerUp(std::string name, cg::Vector3d pos) : cg::Entity(name)
	{
		_position = pos;
	}
    
	PowerUp::~PowerUp(){}
    
	void PowerUp::init()
	{
		_winWidth = cg::Manager::instance()->getApp()->getWindow().width;
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		//_position = cg::Vector3d(30,-100, -400);
		_color = cg::Vector3d(1.0, 0.0, 0.0);
		_initialPos = _position;
		_direction = -1;
		_car = (Car*) cg::Registry::instance()->get("Car");
		
	}
    
	void PowerUp::draw()
	{
		
		glColor3d(_color[0], _color[1], _color[2]);
		glBegin(GL_QUADS);
			//top
			glVertex3d(_position[0]-2, _position[1]+2, -400);       
			glVertex3d(_position[0]-2, _position[1]-2, -400);       
			glVertex3d(_position[0]+2, _position[1]-2, -400);       
			glVertex3d(_position[0]+2, _position[1]+2, -400);
		
			//bottom
			glVertex3d(_position[0]-2, _position[1]+2, -397);       
			glVertex3d(_position[0]-2, _position[1]-2, -395);       
			glVertex3d(_position[0]+2, _position[1]-2, -395);       
			glVertex3d(_position[0]+2, _position[1]+2, -395);
		
			//side1
			glVertex3d(_position[0]-2, _position[1]-2, -400);
			glVertex3d(_position[0]+2, _position[1]-2, -400);
			glVertex3d(_position[0]+2, _position[1]-2, -395);
			glVertex3d(_position[0]-2, _position[1]-2, -395);
		
			//side2
			glVertex3d(_position[0]+2, _position[1]-2, -400);
			glVertex3d(_position[0]+2, _position[1]+2, -400);
			glVertex3d(_position[0]+2, _position[1]+2, -395);
			glVertex3d(_position[0]+2, _position[1]-2, -395);
			
			//side3
			glVertex3d(_position[0]-2, _position[1]+2, -400);
			glVertex3d(_position[0]+2, _position[1]+2, -400);
			glVertex3d(_position[0]+2, _position[1]+2, -395);
			glVertex3d(_position[0]-2, _position[1]+2, -395);
		
			//side4
			glVertex3d(_position[0]-2, _position[1]-2, -400);
			glVertex3d(_position[0]-2, _position[1]+2, -400);
			glVertex3d(_position[0]-2, _position[1]+2, -396);
			glVertex3d(_position[0]-2, _position[1]-2, -396);
		
		glEnd();
	}
	
	void PowerUp::update(unsigned long elapsed_millis) 
	{
	}
	
	cg::Vector3d PowerUp::getPosition()
	{
		return _position;
	}
    
}
