//
//  Room.cpp
//  cglib
//
//  Created by Inês on 4/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Room.h"

namespace Micromachines {
	Room::Room(int floorSize) : cg::Entity("Room")
	{
		_floorSize = cg::Vector2d(-(floorSize/2), floorSize/2);
	}
	
	Room::~Room(){}
	
	void Room::init()
	{
		_textureWall = LoadTexture("src/Textures/wall.bmp");
		_textureFloor = LoadTexture("src/Textures/floor.bmp");
		//_textureCarpet = LoadTexture("src/Textures/carpet.bmp");
		//_table = glmReadOBJ((char*)"src/Models/table.obj");
	}
	
	void Room::drawWalls()
	{	
		glColor3d(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureWall);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glBegin(GL_QUADS);
			glTexCoord2d(0.1, 0.1);
			glVertex3d(_floorSize[0], _floorSize[1], -410);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(_floorSize[1], _floorSize[1], -410);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(_floorSize[1], _floorSize[1], 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(_floorSize[0], _floorSize[1], 400);
		
			glTexCoord2d(0.1, 0.1);
			glVertex3d(_floorSize[1], _floorSize[0], -410);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(_floorSize[1], _floorSize[1], -410);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(_floorSize[1], _floorSize[1], 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(_floorSize[1], _floorSize[0], 400);
		
			glTexCoord2d(0.1, 0.1);
			glVertex3d(_floorSize[1], _floorSize[0], -410);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(_floorSize[0], _floorSize[0], -410);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(_floorSize[0], _floorSize[0], 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(_floorSize[1], _floorSize[0], 400);
		
			glTexCoord2d(0.1, 0.1);
			glVertex3d(_floorSize[0], _floorSize[1], -410);
			glTexCoord2d(0.9, 0.1);
			glVertex3d(_floorSize[0], _floorSize[0], -410);
			glTexCoord2d(0.9, 0.9);
			glVertex3d(_floorSize[0], _floorSize[0], 400);
			glTexCoord2d(0.1, 0.9);
			glVertex3d(_floorSize[0], _floorSize[1], 400);
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
			glVertex3d(_floorSize[0], _floorSize[0], -400.15);
			glTexCoord2d(50, 0);
			glVertex3d(_floorSize[1], _floorSize[0], -400.15);
			glTexCoord2d(50, 50);
			glVertex3d(_floorSize[1], _floorSize[1], -400.15);
			glTexCoord2d(0, 50);
			glVertex3d(_floorSize[0], _floorSize[1], -400.15);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
	}
	
	void Room::drawCarpet()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureCarpet);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glColor3d(0, 0, 0);
		
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0);
			glVertex3d(0, 0, -400.05);
			glTexCoord2d(10, 0);
			glVertex3d(600, 0, -400.05);
			glTexCoord2d(10, 10);
			glVertex3d(600, 500, -400.05);
			glTexCoord2d(0, 10);
			glVertex3d(0, 500, -400.05);
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
		
	}
	
	void Room::drawTable()
	{
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glTranslatef(100,100,-400);
		glRotated(90, 1.0, 0.0, 0.0);
		glRotated(180, 0.0, 1.0, 0.0);
		glmDraw(_table,GLM_MATERIAL|GLM_SMOOTH);
		glPopMatrix();
		
	}
	
	void Room::draw()
	{
		drawWalls();
		drawFloor();
		//drawCarpet();
		//drawTable();
	}
}
