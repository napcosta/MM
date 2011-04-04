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

namespace Micromachines {
	class Room : public cg::Entity, public cg::IDrawListener
	{
	private:
		GLuint _textureWall, _textureFloor;
		
	public:
		Room();
		~Room();
		void init();
		void draw();
	};
}

#endif