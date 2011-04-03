//
//  TrackPiece.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TrackPiece.h"

namespace Micromachines 
{
    
	/******************************/
	/*            Type 1           */
	/*******************************/
	/*                             */
	/*         |           |       */
	/*         |           |       */
	/*         |           |       */
	/*         |           |       */
	/*         |           |       */
	/*         |           |       */
	/*         |           |       */
	/*         |           |       */
	/*                             */
	/*******************************/
    
	void TrackPiece::drawType1()
	{
		glBegin(GL_LINES);
			glVertex3d(_position[0]-27, _position[1]+54, -400);
			glVertex3d(_position[0]-27, _position[1]-54, -400);
			glVertex3d(_position[0]+27, _position[1]+54, -400);
			glVertex3d(_position[0]+27, _position[1]-54, -400);
		glEnd();
	}
    
	/******************************/
	/*            Type 2           */
	/*******************************/
	/*                             */
	/*               ________      */
	/*              /              */
	/*             /               */
	/*            /         _      */
	/*           /         /       */
	/*          /         /        */
	/*         /         /         */
	/*        /         /          */
	/*       |         |           */
	/*                             */
	/*******************************/
    
	void TrackPiece::drawType2()
	{
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]-27, _position[1]-54, -400);
			glVertex3d(_position[0]-27, _position[1]-54, -400);
			glVertex3d(_position[0]-9, _position[1]-9, -400);
			glVertex3d(_position[0]+9, _position[1]+9, -400);
			glVertex3d(_position[0]+45, _position[1]+27, -400);
			glVertex3d(_position[0]+54, _position[1]+27, -400);
		glEnd();
        
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]+27, _position[1]-54, -400);
			glVertex3d(_position[0]+27, _position[1]-45, -400);
			glVertex3d(_position[0]+45, _position[1]-27, -400);
			glVertex3d(_position[0]+54, _position[1]-27, -400);
		glEnd();
	}
    
	/******************************/
	/*            Type 3           */
	/*******************************/
	/*                             */
	/*      ________               */
	/*              \              */
	/*               \             */
	/*      _         \            */
	/*       \         \           */
	/*        \         \          */
	/*         \         \         */
	/*          \         \        */
	/*          |         |        */
	/*                             */
	/*******************************/
    
	void TrackPiece::drawType3()
	{
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]-54, _position[1]+27, -400);
			glVertex3d(_position[0]-45, _position[1]+27, -400);
			glVertex3d(_position[0]-9, _position[1]+9, -400);
			glVertex3d(_position[0]+9, _position[1]-9, -400);
			glVertex3d(_position[0]+27, _position[1]-45, -400);
			glVertex3d(_position[0]+27, _position[1]-54, -400);
		glEnd();
        
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]-54, _position[1]-27, -400);
			glVertex3d(_position[0]-45, _position[1]-27, -400);
			glVertex3d(_position[0]-27, _position[1]-45, -400);
			glVertex3d(_position[0]-27, _position[1]-54, -400);
		glEnd();
	}
    
	/******************************/
	/*            Type 4           */
	/*******************************/
	/*                             */
	/*      |         |            */
	/*       \         \           */
	/*        \         \          */
	/*         \         \         */
	/*          \         \_       */
	/*           \                 */
	/*            \                */
	/*             \________       */
	/*                             */
	/*******************************/
    
	void TrackPiece::drawType4()
	{ 
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]-27, _position[1]+54, -400);
			glVertex3d(_position[0]-27, _position[1]+45, -400);
			glVertex3d(_position[0]-9, _position[1]+9, -400);
			glVertex3d(_position[0]+9, _position[1]-9, -400);
			glVertex3d(_position[0]+45, _position[1]-27, -400);
			glVertex3d(_position[0]+54, _position[1]-27, -400);
		glEnd();
        
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]+27, _position[1]+54, -400);
			glVertex3d(_position[0]+27, _position[1]+45, -400);
			glVertex3d(_position[0]+45, _position[1]+27, -400);
			glVertex3d(_position[0]+54, _position[1]+27, -400);
		glEnd();
	}
    
	/******************************/
	/*            Type 5           */
	/*******************************/
	/*                             */
	/*           |         |       */
	/*          /         /        */
	/*         /         /         */
	/*        /         /          */
	/*      _/         /           */
	/*                /            */
	/*               /             */
	/*      ________/              */
	/*                             */
	/*******************************/
    
	void TrackPiece::drawType5()
	{ 
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]+27, _position[1]+54, -400);
			glVertex3d(_position[0]+27, _position[1]+45, -400);
			glVertex3d(_position[0]+9, _position[1]+9, -400);
			glVertex3d(_position[0]-9, _position[1]-9, -400);
			glVertex3d(_position[0]-45, _position[1]-27, -400);
			glVertex3d(_position[0]-54, _position[1]-27, -400);
		glEnd();
        
		glBegin(GL_LINE_STRIP);
			glVertex3d(_position[0]-27, _position[1]+54, -400);
			glVertex3d(_position[0]-27, _position[1]+45, -400);
			glVertex3d(_position[0]-45, _position[1]+27, -400);
			glVertex3d(_position[0]-54, _position[1]+27, -400);
		glEnd();
	}
    
	/******************************/
	/*            Type 6           */
	/*******************************/
	/*                             */
	/*     ___________________     */
	/*                             */
	/*                             */
	/*                             */
	/*                             */
	/*                             */
	/*                             */
	/*     ____________________    */
	/*                             */
	/*******************************/
    
	void TrackPiece::drawType6()
	{
		glBegin(GL_LINES);
			glVertex3d(_position[0]-54, _position[1]+27, -400);
			glVertex3d(_position[0]+54, _position[1]+27, -400);
			glVertex3d(_position[0]-54, _position[1]-27, -400);
			glVertex3d(_position[0]+54, _position[1]-27, -400);
		glEnd();
	}
    
	TrackPiece::TrackPiece(std::string name, int type, cg::Vector2d position) : cg::Entity(name)
	{
		_type = type;
		_position = position;
	}
    
	TrackPiece::~TrackPiece(){}
    
	void TrackPiece::init(){}
    
	void TrackPiece::draw()
	{
		glColor3d(1, 0, 0);		
		glLineWidth(1.5);
		if (_type == 1) {
			drawType1();
		} else if (_type == 2){
			drawType2();
		} else if (_type == 3){
			drawType3();
		} else if (_type == 4){
			drawType4();
		} else if (_type == 5){
			drawType5();
		} else drawType6();
	}
}