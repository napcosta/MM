/*
 * NearCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DoubleCamera.h"
#include "Car.h"
#include "PlayerManager.h"
#include <math.h>
#include <algorithm>
#include <iostream>
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
			double xDistance = 0;
			double yDistance = 0;
			double distance = 0;
			double cameraDistance = 0;
			
			cg::Vector3d position = cg::Vector3d((_posPlayer1[0]+_posPlayer2[0])/2, (_posPlayer1[1]+_posPlayer2[1])/2, _posPlayer1[2]);
			
			
			if (_posPlayer1[0] >_posPlayer2[0])
				xDistance = fabs(_posPlayer1[0]-_posPlayer2[0]);
			else
				xDistance = fabs(_posPlayer1[0]-_posPlayer2[0]);
				
			if (_posPlayer1[1] >_posPlayer2[1])
				yDistance = fabs(_posPlayer1[1]-_posPlayer2[1]);
			else
				yDistance = fabs(_posPlayer1[1]-_posPlayer2[1]);
			
			distance = sqrt((yDistance + xDistance) * (yDistance + xDistance));
			
			
			if (distance < 200)
				cameraDistance = distance;
			else
				cameraDistance = 200;
				
			std::cout << cameraDistance << std::endl;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60, _winWidth/_winHeight, 1, 3000);
			gluLookAt(-position[0] -50 - cameraDistance*0.3 , -position[1]- 50 - cameraDistance*0.3 , -355 + cameraDistance*0.1, 
				  -position[0], -position[1], -396, 
				  0, 0 , 1);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

	}
}


