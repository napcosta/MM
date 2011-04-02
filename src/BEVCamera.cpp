/*
 * BEVCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "BEVCamera.h"

namespace Micromachines {

	BEVCamera::BEVCamera() : Entity("BEVCamera")
	{
	}

	BEVCamera::~BEVCamera()
	{
	}

	void BEVCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_car = (Car*) cg::Registry::instance()->get("Car");
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void BEVCamera::draw()
	{
		_position = -_car->getPosition();
		_carRotation = _car->getRotation();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	//	glOrtho(0, _winWidth, 0, _winHeight, 0, -100);
	//	glViewport(-100,-100,_winWidth,_winHeight);
		gluPerspective(60, _winWidth/_winHeight, 1, 402);
		//glTranslatef(_position[0],_position[1],200);
		//glTranslatef(0,0,0);
		printf("_position[0] %f - _position[1] %f \n", _position[0], _position[1]);
		gluLookAt(-(_position[0]-100)*cos(_carRotation*PI/180 + PI/2), -_position[1]*sin(_carRotation*PI/180 + PI/2), -200, -_position[0], -_position[1], -500, 0, 1, 0);
	//	glViewport(0,0,400,200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

}
