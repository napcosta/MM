/*
 * BEVCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "FarCamera.h"
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {

	FarCamera::FarCamera() : Entity("FarCamera")
	{
	}

	FarCamera::~FarCamera()
	{
	}

	void FarCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_pm = (PlayerManager*) cg::Registry::instance()->get("PlayerManager");
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void FarCamera::draw()
	{
		if (_car == NULL) {
			std::vector<Car*> players = _pm->getPlayers();
			_car = players[0];
		} else {
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
			gluLookAt(-(_position[0]+100*cos(_carRotation*PI/180 + PI/2)), -(_position[1]+100*sin(_carRotation*PI/180 + PI/2)), -300, -_position[0], -_position[1], -400, cos(_carRotation*PI/180 + PI/2), sin(_carRotation*PI/180 + PI/2), 0);
			//	glViewport(0,0,400,200);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
	}

}
