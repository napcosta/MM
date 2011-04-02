/*
 * NearCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "NearCamera.h"

namespace Micromachines {

	NearCamera::NearCamera() : Entity("NearCamera")
	{
	}

	NearCamera::~NearCamera()
	{
	}

	void NearCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_car = (Car*) cg::Registry::instance()->get("Car");
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void NearCamera::draw()
	{
		_position = -_car->getPosition();
		_carRotation = _car->getRotation();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	//	glOrtho(0, _winWidth, 0, _winHeight, 0, -100);
	//	glViewport(-100,-100,_winWidth,_winHeight);
		gluPerspective(60, _winWidth/_winHeight, 1, 1000);
		//glTranslatef(_position[0],_position[1],200);
		//glTranslatef(0,0,0);
//		printf("_position[0] %f - _position[1] %f \n", _position[0], _position[1]);
		gluLookAt(-_position[0]-50*cos(_carRotation*PI/180 + PI/2), 
				-_position[1] - 50*sin(_carRotation*PI/180 + PI/2), 
				-390, 
				-_position[0], -_position[1], -400, 0, 0 , 1);
	//	glViewport(0,0,400,200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

}
