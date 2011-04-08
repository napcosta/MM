//
//  Room.h
//  cglib
//
//  Created by Inês on 4/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef ROOM_H
#define ROOM_H

#include "cg.h"
#include "ImageLoader.h"
#include "glm.h"

namespace Micromachines {
	class Room : public cg::Entity, public cg::IDrawListener
	{
	private:
		GLuint _textureWall, _textureFloor, _textureCarpet;
		GLMmodel *_table;
		cg::Vector2d _floorSize;
		
		void drawWalls();
		void drawFloor();
		void drawCarpet();
		void drawTable();
		
	public:
		Room(int floorSize);
		~Room();
		void init();
		void draw();
	};
}

#endif