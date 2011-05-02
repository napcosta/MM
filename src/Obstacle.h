//
//  Obstacle.h
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#define MAX_MOV 10
#define VELOCITY 0.1

#include "cg.h"

namespace Micromachines {
	class Obstacle : public cg::Entity,
	public cg::IDrawListener,
	public cg::IUpdateListener
	{
	private:
		int _direction;
		cg::Vector3d _position, _color, _initialPos;
		double _winHeight, _winWidth;
		bool _isMovable;
        
		int RandomBeetween(int min, int max);
		void drawCircle();
		void drawRectangle();
		void drawTriangle();
        
	public:
		Obstacle(std::string name);
		~Obstacle();
		cg::Vector3d getPosition();
		void init();
		void draw();
		void update(unsigned long elapsed_millis);
	};
}

#endif