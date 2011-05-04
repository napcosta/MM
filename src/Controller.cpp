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
		_player1 = (Car*) cg::Registry::instance()->get("Car");
		//_player2 = (Car*) cg::Registry::instance()->get("Player2");
		_dirKeysP1 = cg::Vector2d(0.0, 0.0);
	//	_dirKeysP2 = cg::Vector2d(0.0, 0.0);
	}

	void Controller::onKeyPressed(unsigned char key)
	{
		if (key == 27) {
			cg::Manager::instance()->shutdownApp();
		}/* else {
			//for player2
			cg::Vector2d keys = _player2->getArrowKeyPressed();
			switch (key) {
				case 'w':
					_dirKeysP2[1]=0.02;
					keys[1] += 1;
					break;
				case 's':
					_dirKeysP2[1]= -0.05;
					keys[1] -= 1;
					break;
				case 'a':
					_dirKeysP2[0] += _player2->getRotationSpeed();
					keys[0] -= 1;
					break;
				case 'd':
					_dirKeysP2[0] -= _player2->getRotationSpeed();
					keys[0] += 1;
					break;
			}
			_player2->applyForce(_dirKeysP2);
			_player2->setArrowKeyPressed(keys);
		}*/
	}

	void Controller::onKeyReleased(unsigned char key)
	{
/*		//for player2
		cg::Vector2d arrowKeyPressed = _player2->getArrowKeyPressed();
		switch (key) {
			case 'w':
				_dirKeysP2[1] = -_player2->getMovForce();
				arrowKeyPressed[1] -=1;
				break;
			case 's':
				_dirKeysP2[1] = _player2->getMovForce();
				arrowKeyPressed[1] += 1;
				break;
			case 'a':
				_dirKeysP2[0] -= _player2->getRotationSpeed();
				arrowKeyPressed[0] += 1;
				break;
			case 'd':
				_dirKeysP2[0] += _player2->getRotationSpeed();
				arrowKeyPressed[0] -= 1;
				break;
		}
		_player2->applyForce(_dirKeysP2);
		_player2->setArrowKeyPressed(arrowKeyPressed);*/
	}

	void Controller::onSpecialKeyPressed(int key)
	{
		//for player1
		cg::Vector2d keys = _player1->getArrowKeyPressed();
		switch (key) {
		case GLUT_KEY_UP:
			_dirKeysP1[1]=0.02;
			keys[1] += 1;
			break;
		case GLUT_KEY_DOWN:
			_dirKeysP1[1]= -0.05;
			keys[1] -= 1;
			break;
		case GLUT_KEY_LEFT:
			_dirKeysP1[0] += _player1->getRotationSpeed();
			keys[0] -= 1;
			break;
		case GLUT_KEY_RIGHT:
			_dirKeysP1[0] -= _player1->getRotationSpeed();
			keys[0] += 1;
 			break;
		}
		_player1->applyForce(_dirKeysP1);
		_player1->setArrowKeyPressed(keys);
		
	}

	void Controller::onSpecialKeyReleased(int key)
	{
		//for player1
		cg::Vector2d arrowKeyPressed = _player1->getArrowKeyPressed();
		switch (key) {
		case GLUT_KEY_UP:
			_dirKeysP1[1] = -_player1->getMovForce();
			arrowKeyPressed[1] -=1;
			break;
		case GLUT_KEY_DOWN:
			_dirKeysP1[1] = _player1->getMovForce();
			arrowKeyPressed[1] += 1;
			break;
		case GLUT_KEY_LEFT:
			_dirKeysP1[0] -= _player1->getRotationSpeed();
			arrowKeyPressed[0] += 1;
			break;
		case GLUT_KEY_RIGHT:
			_dirKeysP1[0] += _player1->getRotationSpeed();
			arrowKeyPressed[0] -= 1;
			break;
		}
		_player1->applyForce(_dirKeysP1);
		_player1->setArrowKeyPressed(arrowKeyPressed);
		
	}

}
