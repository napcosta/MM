/*
 * NearCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DoubleCamera.h"
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {

	DoubleCamera::DoubleCamera() : Entity("NearCamera")
	{
	}

	DoubleCamera::~DoubleCamera()
	{
	}

	void DoubleCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_pm = (PlayerManager*) cg::Registry::instance()->get("PlayerManager");
		_player1 = NULL;
		_player2 = NULL;
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void DoubleCamera::draw()
	{	
		cg::Vector3d _posPlayer1;
		cg::Vector3d _posPlayer2;
		
		if (_player1 == NULL){
			_player1 = _pm->firstPlayer();
			_position = _player1->getPosition();
		} else if (_pm->hasTwoPlayers() && _player2 == NULL) {
			_player2 = _pm->secondPlayer();
		} else if (!_pm->hasTwoPlayers()){
			cg::Vector3d positionP1 = -_player1->getPosition();
			
			if(_position[0] > positionP1[0] + 1)
				_position[0] = _position[0] - 0.5;
			else if (_position[0] < positionP1[0] - 1)
				_position[0] = _position[0] + 0.5;
			else _position[0] = positionP1[0];
			
			if (_position[1] > positionP1[1] + 1)
				_position[1] = _position[1] - 0.5;
			else if (_position[1] < positionP1[1] - 1)
				_position[1] = _position[1] + 0.5;
			else _position[1] = positionP1[1];
			
			_position[2] = positionP1[2];
			
		} else {
			_posPlayer1 = -_player1->getPosition();
			_posPlayer2 = -_player2->getPosition();
			
			cg::Vector3d midlePoint = cg::Vector3d((_posPlayer1[0]+_posPlayer2[0])/2, (_posPlayer1[1]+_posPlayer2[1])/2, _posPlayer1[2]);
			
			
			if(_position[0] > midlePoint[0] + 1)
				_position[0] = _position[0] - 0.5;
			else if (_position[0] < midlePoint[0] - 1)
				_position[0] = _position[0] + 0.5;
			else _position[0] = midlePoint[0];
			
			if (_position[1] > midlePoint[1] + 1)
				_position[1] = _position[1] - 0.5;
			else if (_position[1] < midlePoint[1] - 1)
				_position[1] = _position[1] + 0.5;
			else _position[1] = midlePoint[1];
			
			_position[2] = midlePoint[2];
		}
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, _winWidth/_winHeight, 1, 3000);
		gluLookAt(-_position[0] -100 , -_position[1], -355, 
			  -_position[0], -_position[1], -396, 
			  0, 0 , 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

	}
}


