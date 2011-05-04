/*
 * Controller.cpp
 *
 *  Created on: Aug 2, 2010
 *      Author: pinto
 */

#include "Controller.h"
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {

	Controller::Controller() : cg::Entity("Controller")
	{
		_2Players = false;
	}

	Controller::~Controller()
	{
	}

	void Controller::init()
	{
		_dirKeysP1 = cg::Vector2d(0.0, 0.0);
		_dirKeysP2 = cg::Vector2d(0.0, 0.0);
		_pm = (PlayerManager*) cg::Registry::instance()->get("PlayerManager");
		_firstPlayer = NULL;
		_secondPlayer = NULL;
	}
	
	void Controller::keyPressed(int key)
	{
		//for player2
		cg::Vector2d keys = _secondPlayer->getArrowKeyPressed();
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
				_dirKeysP2[0] += _secondPlayer->getRotationSpeed();
				keys[0] -= 1;
				break;
			case 'd':
				_dirKeysP2[0] -= _secondPlayer->getRotationSpeed();
				keys[0] += 1;
				break;
		}
		_secondPlayer->applyForce(_dirKeysP2);
		_secondPlayer->setArrowKeyPressed(keys);

	}
	
	void Controller::keyReleased(int key)
	{
		//for player2
		cg::Vector2d arrowKeyPressed = _secondPlayer->getArrowKeyPressed();
		switch (key) {
			case 'w':
				_dirKeysP2[1] = -_secondPlayer->getMovForce();
				arrowKeyPressed[1] -=1;
				break;
			case 's':
				_dirKeysP2[1] = _secondPlayer->getMovForce();
				arrowKeyPressed[1] += 1;
				break;
			case 'a':
				_dirKeysP2[0] -= _secondPlayer->getRotationSpeed();
				arrowKeyPressed[0] += 1;
				break;
			case 'd':
				_dirKeysP2[0] += _secondPlayer->getRotationSpeed();
				arrowKeyPressed[0] -= 1;
				break;
		}
		_secondPlayer->applyForce(_dirKeysP2);
		_secondPlayer->setArrowKeyPressed(arrowKeyPressed);
	}

	void Controller::onKeyPressed(unsigned char key)
	{
		if (key == 27) {
			cg::Manager::instance()->shutdownApp();
		} else if (key == '2'){
			
			if(_2Players)
				_2Players = false;
			else 
				_2Players = true;
			_pm->addOrRemovePlayer2();
			
		} else if (_2Players) {
			if (_secondPlayer == NULL){
				_secondPlayer = _pm->secondPlayer();
				keyPressed(key);
			}
			else keyPressed(key);
		}
	}

	void Controller::onKeyReleased(unsigned char key)
	{
		if(_2Players){
			if (_secondPlayer == NULL){
				_secondPlayer = _pm->secondPlayer();
				keyReleased(key);
			}
			else keyReleased(key);
		}
	}
	
	void Controller::specialKeyPressed(int key)
	{
		//for player1
		cg::Vector2d keys = _firstPlayer->getArrowKeyPressed();
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
				_dirKeysP1[0] += _firstPlayer->getRotationSpeed();
				keys[0] -= 1;
				break;
			case GLUT_KEY_RIGHT:
				_dirKeysP1[0] -= _firstPlayer->getRotationSpeed();
				keys[0] += 1;
				break;
		}
		_firstPlayer->applyForce(_dirKeysP1);
		_firstPlayer->setArrowKeyPressed(keys);
	}
	
	void Controller::specialKeyReleased(int key)
	{
		//for player1
		cg::Vector2d arrowKeyPressed = _firstPlayer->getArrowKeyPressed();
		switch (key) {
			case GLUT_KEY_UP:
				_dirKeysP1[1] = -_firstPlayer->getMovForce();
				arrowKeyPressed[1] -=1;
				break;
			case GLUT_KEY_DOWN:
				_dirKeysP1[1] = _firstPlayer->getMovForce();
				arrowKeyPressed[1] += 1;
				break;
			case GLUT_KEY_LEFT:
				_dirKeysP1[0] -= _firstPlayer->getRotationSpeed();
				arrowKeyPressed[0] += 1;
				break;
			case GLUT_KEY_RIGHT:
				_dirKeysP1[0] += _firstPlayer->getRotationSpeed();
				arrowKeyPressed[0] -= 1;
				break;
		}
		_firstPlayer->applyForce(_dirKeysP1);
		_firstPlayer->setArrowKeyPressed(arrowKeyPressed);
	}

	void Controller::onSpecialKeyPressed(int key)
	{
		if(_firstPlayer == NULL){
			_firstPlayer = _pm->firstPlayer();
			specialKeyPressed(key);
		}
		else specialKeyPressed(key);
		
	}

	void Controller::onSpecialKeyReleased(int key)
	{
		if(_firstPlayer == NULL){
			_firstPlayer = _pm->firstPlayer();
			specialKeyReleased(key);
		}
		else specialKeyReleased(key);
		
	}
}
