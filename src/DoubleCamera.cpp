/*
 * NearCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DoubleCamera.h"

namespace Micromachines {

	DoubleCamera::DoubleCamera() : Entity("NearCamera")
	{
	}

	DoubleCamera::~DoubleCamera()
	{
	}

	void DoubleCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_car = (Car*) cg::Registry::instance()->get("Car");
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void DoubleCamera::draw()
	{	
		_position = -_car->getPosition();
		double _rotation = _car->getRotation();

				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(60, _winWidth/_winHeight, 1, 3000);
				gluLookAt(-_position[0], -_position[1] +0.01, -355, 
						-_position[0], -_position[1], -396, 
						0, 0 , 1);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

	}
}


