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
    
	PowerUp::PowerUp(std::string name, cg::Vector3d pos) : Collidable(name)
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
		_size = cg::Vector2d(0, 0);
		_draw = true;
		int t = 0;
	}
    
	void PowerUp::draw()
	{
		if (_draw) {
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
	}
	
	void PowerUp::notDraw()
	{
		_draw = false;
	}
	
	bool PowerUp::isDraw()
	{
		return _draw;
	}
	
	void PowerUp::update(unsigned long elapsed_millis) 
	{
		if (_draw == false) {
			t = (glutGet(GLUT_ELAPSED_TIME)/1000)%60;
			if (t > 30) {
				_draw = true;
				t = 0;
			}
		}
	//	_draw = false;
		
	}
	
	cg::Vector3d PowerUp::getPosition()
	{
		return _position;
	}
	
	cg::Vector2d PowerUp::getSize()
	{
		return _size;
	}
    
}
