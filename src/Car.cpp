/*
 * Car.cpp
 *
 *  Created on: Jul 25, 2010
 *      Author: pinto
 */

//TODO: Code must be cleaned. Most of it belongs in Controller.cpp and PhysicalEntity.cpp
// and the .ini file should be updated with the physical parameters for the matter.
//TODO: Speed should be normalized

#include "Car.h"

namespace Micromachines {

	Car::Car(std::string id) : cg::Entity(id)
	{
	}

	Car::~Car()
	{
	}

	void Car::init()
	{
		_size = cg::Properties::instance()->getVector2d("BAT_SIZE");
		_maxSpeed = cg::Properties::instance()->getDouble("CAR_MAX_SPEED");
		_movForce = cg::Properties::instance()->getDouble("CAR_MOV_FORCE");
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		_velocity = cg::Vector2d(0.0, 0.0);
		_appForce = cg::Vector2d(0.0,0.0);
		_acceleration = cg::Vector2d(0.0, 0.0);
		_atrittionFactor = 100;
		_mass = 500;
		_arrowKeyPressed =cg::Vector2d(0.0, 0.0);
        
        model = glmReadOBJ((char*)"src/Models/smart.obj");

        
		glmUnitize(model);
        glmFacetNormals(model);
        glmVertexNormals(model, 90.0);
 		glmScale(model, _size[0]);
        
	}

	void Car::draw()
	{

		/*cg::Vector2d min = _position - _size/2.0;
		cg::Vector2d max = _position + _size/2.0;
		glColor3d(0.9, 0.9, 0.9);
		glLineWidth(1.5);
		glLineWidth(1.5);
		glBegin(GL_LINE_LOOP);
			glVertex3d(min[0], min[1], -400);
			glVertex3d(max[0], min[1], -400);
			glVertex3d(max[0], max[1], -400);
			glVertex3d(min[0], max[1], -400);
		glEnd();*/
        
        glColor3d(0.2, 0.3, 0.4);
		glLineWidth(1);
		glMatrixMode(GL_PROJECTION);
		
		glPushMatrix();
            glTranslatef(_position[0], _position[1], -400);
            glRotated(90, 1.0, 0.0, 0.0);
            glRotated(180, 0.0, 1.0, 0.0);
            glScalef(0.4, 0.4, 0.4);
            glmDraw(model,GLM_MATERIAL|GLM_SMOOTH);
		glPopMatrix();
	}

	void Car::update(unsigned long elapsed_millis)
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

	void Car::applyForce(cg::Vector2d force)
	{
		_appForce = force;
	}

	void Car::keyBreak(int direction)
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

	cg::Vector2d Car::getArrowKeyPressed() {
		return _arrowKeyPressed;
	}

	void Car::setArrowKeyPressed(cg::Vector2d val)
	{
		_arrowKeyPressed = val;
	}

	void Car::onMouse(int Button, int state, int x, int y)
	{
	}

	void Car::onMouseMotion(int x, int y)
	{
	}

	void Car::onMousePassiveMotion(int x, int y)
	{
		_position[0] = x;
		_position[1] = _winHeight -y;
	}
}
