//
//  Obstacle.h
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef POWERUP_H
#define POWERUP_H

#define MAX_MOV 10
#define VELOCITY 0.1

#include "cg.h"
#include "Collidable.h"

namespace Micromachines {
	class PowerUp : public Collidable
	{
	private:
		int _direction;
		cg::Vector3d _position, _color, _initialPos;
		double _winHeight, _winWidth;
		cg::Vector2d _size;
		int RandomBeetween(int min, int max);
      //  	GLMmodel *model;
        
	public:
		PowerUp(std::string name, cg::Vector3d pos);
		~PowerUp();
		void init();
		void draw();
		void update(unsigned long elapsed_millis);
		cg::Vector3d getPosition();
		cg::Vector2d getSize();
	};
}

#endif
