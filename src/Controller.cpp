/*
 * Controller.cpp
 *
 *  Created on: Aug 2, 2010
 *      Author: pinto
 */
#include<stdio.h>

#include "Controller.h"
#include "Car.h"

namespace Micromachines {

	Controller::Controller() : cg::Entity("Controller")
	{
	}

	Controller::~Controller()
	{
	}

	void Controller::init()
	{
		_car = (Car*) cg::Registry::instance()->get("Car");
		_dirKeys = cg::Vector2d(0.0, 0.0);
	}

	void Controller::onKeyPressed(unsigned char key)
	{
		if (key == 27) {
			cg::Manager::instance()->shutdownApp();
		}
	}

	void Controller::onKeyReleased(unsigned char key)
	{

	}

	void Controller::onSpecialKeyPressed(int key)
	{
		cg::Vector2d keys = _car->getArrowKeyPressed();
		switch (key) {
		case GLUT_KEY_UP:
			_dirKeys[1]=1;
			keys[1] += 1;
			break;
		case GLUT_KEY_DOWN:
			_dirKeys[1]=-1;
			keys[1] -= 1;
			break;
		case GLUT_KEY_LEFT:
			_dirKeys[0]=-1;
			keys[0] -= 1;
			break;
		case GLUT_KEY_RIGHT:
			_dirKeys[0]=1;
			keys[0] += 1;
 			break;
		}
		_car->applyForce(_dirKeys);
		_car->setArrowKeyPressed(keys);

	}

	void Controller::onSpecialKeyReleased(int key)
	{
		int left=1;
		int up=2;
		int right=3;
		int down=4;
		switch (key) {
		case GLUT_KEY_UP:
			_dirKeys[1]=0;
			_car->keyBreak(up);
			break;
		case GLUT_KEY_DOWN:
			_dirKeys[1]=0;
			_car->keyBreak(down);
			break;
		case GLUT_KEY_LEFT:
			_dirKeys[0]=0;
			_car->keyBreak(left);
			break;
		case GLUT_KEY_RIGHT:
			_dirKeys[0]=0;
			_car->keyBreak(right);
			break;
		}
	}
}
