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
#include "PlayerManager.h"

namespace Micromachines {
	class PowerUp : public cg::Entity,
	public cg::IDrawListener
	{
	private:
		int _direction;
		cg::Vector3d _position, _color, _initialPos;
		double _winHeight, _winWidth;
		PlayerManager* _playerManager;
        
		int RandomBeetween(int min, int max);
        
	public:
		PowerUp(std::string name);
		~PowerUp();
		void init();
		void draw();
	};
}

#endif
