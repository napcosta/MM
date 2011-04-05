//
//  Room.cpp
//  cglib
//
//  Created by Inês on 4/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Room.h"

namespace Micromachines {
	Room::Room() : cg::Entity("Room"){}
	
	Room::~Room(){}
	
	void Room::init()
	{
		_textureWall = LoadTexture("src/Textures/wall.bmp");
		_textureFloor = LoadTexture("src/Textures/floor.bmp");
		_textureCarpet = LoadTexture("src/Textures/carpet.bmp");
	}
	
	void Room::drawWalls()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureWall);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glBegin(GL_QUADS);
			glTexCoord2d(0.1, 0.1);
			glVertex3d(-700, 700, -400);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(700, 700, -400);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(700, 700, 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(-700, 700, 400);
		
			glTexCoord2d(0.1, 0.1);
			glVertex3d(700, -700, -400);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(700, 700, -400);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(700, 700, 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(700, -700, 400);
		
			glTexCoord2d(0.1, 0.1);
			glVertex3d(-700, -700, -400);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(700, -700, -400);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(700, -700, 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(-700, -700, 400);
		
			glTexCoord2d(0.1, 0.1);
			glVertex3d(-700, 700, -400);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(-700, -700, -400);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(-700, -700, 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(-700, 700, 400);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
	}
	
	void Room::drawFloor()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureFloor);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(-1010, -1010, -400.15);
			glTexCoord2d(6, 0);
			glVertex3d(1010, -1010, -400.15);
			glTexCoord2d(6, 6);
			glVertex3d(1010, 1010, -400.15);
			glTexCoord2d(0, 6);
			glVertex3d(-1010, 1010, -400.15);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
	}
	
	void Room::drawCarpet()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureCarpet);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(0, 0, -400.05);
			glTexCoord2d(5, 0);
			glVertex3d(600, 0, -400.05);
			glTexCoord2d(5, 5);
			glVertex3d(600, 500, -400.05);
			glTexCoord2d(0, 5);
			glVertex3d(0, 500, -400.05);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
		
	}
	
	void Room::draw()
	{
		drawWalls();
		drawFloor();
		drawCarpet();
	}
}
