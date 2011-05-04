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
		
		if (_player1 == NULL || (_pm->hasTwoPlayers() && _player2 == NULL)) {
			_player1 = _pm->firstPlayer();
			_player2 = _pm->secondPlayer();
		} else if (!_pm->hasTwoPlayers()){
			_posPlayer1 = -_player1->getPosition();
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60, _winWidth/_winHeight, 1, 3000);
			gluLookAt(-_posPlayer1[0] -100 , -_posPlayer1[1], -355, 
				  -_posPlayer1[0], -_posPlayer1[1], -396, 
				  0, 0 , 1);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		} else {
			_posPlayer1 = -_player1->getPosition();
			_posPlayer2 = -_player2->getPosition();
			
			cg::Vector3d position = cg::Vector3d((_posPlayer1[0]+_posPlayer2[0])/2, (_posPlayer1[1]+_posPlayer2[1])/2, _posPlayer1[2]);
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60, _winWidth/_winHeight, 1, 3000);
			gluLookAt(-position[0] -100 , -position[1], -355, 
				  -position[0], -position[1], -396, 
				  0, 0 , 1);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

	}
}


