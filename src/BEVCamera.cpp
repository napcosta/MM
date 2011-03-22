/*
 * BEVCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "BEVCamera.h"

namespace Armageddon {

	BEVCamera::BEVCamera() : Entity("BEVCamera")
	{
	}

	BEVCamera::~BEVCamera()
	{
	}

	void BEVCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void BEVCamera::draw()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	//	glOrtho(0, _winWidth, 0, _winHeight, 0, -100);
	//	glViewport(-100,-100,_winWidth,_winHeight);
		gluPerspective(60, _winWidth/_winHeight, -10, 10.0);
		glTranslatef(-_winWidth/2,-_winHeight/2,0);
	//	glViewport(0,0,400,200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

	}

}
