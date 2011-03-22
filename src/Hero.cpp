/*
 * Hero.cpp
 *
 *  Created on: Jul 25, 2010
 *      Author: pinto
 */

//TODO: Code must be cleaned. Most of it belongs in Controller.cpp and PhysicalEntity.cpp
// and the .ini file should be updated with the physical parameters for the matter.
//TODO: Speed should be normalized

#include "Hero.h"

namespace Armageddon {

	Hero::Hero(std::string id) : cg::Entity(id)
	{
	}

	Hero::~Hero()
	{
	}

	void Hero::init()
	{
		_size = cg::Properties::instance()->getVector2d("BAT_SIZE");
		_maxSpeed = cg::Properties::instance()->getDouble("HERO_MAX_SPEED");
		_movForce = cg::Properties::instance()->getDouble("HERO_MOV_FORCE");
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		_velocity = cg::Vector2d(0.0, 0.0);
		_appForce = cg::Vector2d(0.0,0.0);
		_acceleration = cg::Vector2d(0.0, 0.0);
		_atrittionFactor = 100;
		_mass = 500;
		_arrowKeyPressed =cg::Vector2d(0.0, 0.0);
	}

	void Hero::draw()
	{

		cg::Vector2d min = _position - _size/2.0;
		cg::Vector2d max = _position + _size/2.0;
		glColor3d(0.9, 0.9, 0.9);
		glLineWidth(1.5);
		glLineWidth(1.5);
		glBegin(GL_LINE_LOOP);
			glVertex3d(min[0], min[1], -400);
			glVertex3d(max[0], min[1], -400);
			glVertex3d(max[0], max[1], -400);
			glVertex3d(min[0], max[1], -400);
		glEnd();
	}

	void Hero::update(unsigned long elapsed_millis)
	{


		double time = (double) elapsed_millis;
		if (_velocity[0] < -_maxSpeed)
			_velocity[0] = -_maxSpeed;
		else if (_velocity[0] > _maxSpeed)
			_velocity[0] = _maxSpeed;

		if (_velocity[1] < -_maxSpeed)
			_velocity[1] = -_maxSpeed;
		else if (_velocity[1] > _maxSpeed)
			_velocity[1] = _maxSpeed;

/*		if ( _appForce[0] && _appForce[1]) {
			_appForce[0] = _appForce[0] / sqrt(2.0);
			_appForce[1] = _appForce[1]/sqrt(2.0);
		}

*/
		printf("%f - %f \n", fabs(_velocity[0]), _velocity[1]);

		_acceleration[0] = _appForce[0]/_mass;
		_acceleration[1] = _appForce[1]/_mass;
		_velocity[0] += _acceleration[0]*time;
		_velocity[1] += _acceleration[1]*time;



		if (_appForce[0] > 0 && _velocity[0]<0) {
			if (_velocity[0]>=-0.07 && _arrowKeyPressed[0] != 1) {
				_velocity[0]=0;
				_appForce[0]=0;
				_acceleration[0]=0;
			}
		}

		else if (_appForce[0] < 0 && _velocity[0]>0) {
			if (_velocity[0]<=0.07 &&_arrowKeyPressed[0] != -1) {
				_velocity[0]=0;
				_appForce[0]=0;
				_acceleration[0]=0;
			}
		}

		/* HACK: If the ship is breaking and another key is pressed, this will prevent it from
		 * sailing away on its own */
		else if (_appForce[0] >= 0 && _velocity[0]>0 && _arrowKeyPressed[0] == 0)
			_appForce[0] = -_movForce;

		else if (_appForce[0] <= 0 && _velocity[0] < 0 && _arrowKeyPressed[0] == 0)
			_appForce[0] = _movForce;

		else if (_appForce[1] >= 0 && _velocity[1] > 0 && _arrowKeyPressed[1] == 0)
			_appForce[1] = -_movForce;

		else if (_appForce[1] <= 0 && _velocity[1] < 0 && _arrowKeyPressed[1] == 0)
			_appForce[1] = _movForce;
		/**************************************************************************/

		if (_appForce[1] > 0 && _velocity[1]<0) {
			if (_velocity[1]>=-0.07 && _arrowKeyPressed[1] != 1) {
				_velocity[1]=0;
				_appForce[1]=0;
				_acceleration[1]=0;
			}
		}

		else if (_appForce[1] < 0 && _velocity[1]>0) {
			if (_velocity[1]<=0.07 && _arrowKeyPressed[1] != -1) {
				_velocity[1]=0;
				_appForce[1]=0;
				_acceleration[1]=0;
			}
		}


		_position[0] += _velocity[0]*time + (_acceleration[0]*time*time)/2;
		_position[1] += _velocity[1]*time + (_acceleration[1]*time*time)/2;
	}

	void Hero::applyForce(cg::Vector2d force)
	{
		_appForce = force;
	}

	void Hero::keyBreak(int direction)
	{

		switch (direction) {
		case 1: //LEFT
			_appForce[0] = _movForce;
			_arrowKeyPressed[0] += 1;
			break;
		case 2: //UP
			_appForce[1] = -_movForce;
			_arrowKeyPressed[1] -= 1;
			break;
		case 3: //RIGHT
			_appForce[0] = -_movForce;
			_arrowKeyPressed[0] -= 1;
			break;
		case 4: //DOWN
			_appForce[1] = _movForce;
			_arrowKeyPressed[1] += 1;
			break;

		}
	}

	cg::Vector2d Hero::getArrowKeyPressed() {
		return _arrowKeyPressed;
	}

	void Hero::setArrowKeyPressed(cg::Vector2d val)
	{
		_arrowKeyPressed = val;
	}

	void Hero::onMouse(int Button, int state, int x, int y)
	{
	}

	void Hero::onMouseMotion(int x, int y)
	{
	}

	void Hero::onMousePassiveMotion(int x, int y)
	{
		_position[0] = x;
		_position[1] = _winHeight -y;
	}
}
