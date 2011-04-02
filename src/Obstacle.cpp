//
//  Obstacle.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Obstacle.h"

namespace Micromachines {
    
	int Obstacle::RandomBeetween(int min, int max)
	{
		return (rand() % (max-min) + min);
	}
    
	void Obstacle::drawCircle()
	{
		glBegin(GL_POLYGON);
			glVertex3d(_position[0]-27, _position[1]+9, -400);       
			glVertex3d(_position[0]-27, _position[1]-9, -400);       
			glVertex3d(_position[0]-9, _position[1]-27, -400);       
			glVertex3d(_position[0]+9, _position[1]-27, -400);      
			glVertex3d(_position[0]+27, _position[1]-9, -400);       
			glVertex3d(_position[0]+27, _position[1]+9, -400);       
			glVertex3d(_position[0]+9, _position[1]+27, -400);       
			glVertex3d(_position[0]-9, _position[1]+27, -400);       
		glEnd();
	}
    
	void Obstacle::drawRectangle()
	{
		glBegin(GL_POLYGON);
			glVertex3d(_position[0]-27, _position[1]+18, -400);       
			glVertex3d(_position[0]-27, _position[1]-18, -400);       
			glVertex3d(_position[0]+27, _position[1]-18, -400);       
			glVertex3d(_position[0]+27, _position[1]+18, -400); 
		glEnd();
	}
    
	void Obstacle::drawTriangle()
	{
		glBegin(GL_POLYGON);
			glVertex3d(_position[0]-27, _position[1]-18, -400);       
			glVertex3d(_position[0]+27, _position[1]-18, -400);       
			glVertex3d(_position[0], _position[1]+18, -400);       
		glEnd();
	}
    
	Obstacle::Obstacle(std::string name) : cg::Entity(name){}
    
	Obstacle::~Obstacle(){}
    
	void Obstacle::init()
	{
		_type = RandomBeetween(0, 2);
		printf("%d\n", _type) ;
		_winWidth = cg::Manager::instance()->getApp()->getWindow().width;
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		_position = cg::Vector3d(RandomBeetween(27, (_winWidth-27)), RandomBeetween(27, (_winHeight-27)), -400);
		printf("x = %f y = %f z = %f\n", _position[0], _position[1], _position[2]);
		_color = cg::Vector3d(0.9, 0.9, 0.9);
		int i = rand()%2;
		if (i == 0) {
			_isMovable = true;
		} else _isMovable = false;
		_initialPos = _position;
		_direction = -1;
	}
    
	void Obstacle::draw()
	{
		glColor3d(_color[0], _color[1], _color[2]);
		if (_type == 0) {
			drawCircle();
		}
		else if(_type == 1){
			drawRectangle();
		}
		else drawTriangle();
	}
    
	void Obstacle::update(unsigned long elapsed_millis) 
	{
		if (_isMovable) {
			if(_position[0] <= _initialPos[0] - MAX_MOV){
				_direction = 1;
				_position[0] += VELOCITY;
			}
			if (_position[0] >= _initialPos[0] + MAX_MOV) {
				_direction = -1;
				_position[0] -= VELOCITY;
			}
			if (_position[0] <= _initialPos[0] && _direction == -1){
				_position[0] -= VELOCITY;
			}
			if (_position[0] <= _initialPos[0] && _direction == 1){
				_position[0] += VELOCITY;
			}
			if (_position[0] > _initialPos[0] && _direction == -1){
				_position[0] -= VELOCITY;
			}
			if (_position[0] > _initialPos[0] && _direction == 1){
				_position[0] += VELOCITY;
			}
		}
	}
    
}