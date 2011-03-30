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
		_size = cg::Properties::instance()->getInt("CAR_SIZE");
		_maxSpeed = cg::Properties::instance()->getDouble("CAR_MAX_SPEED");
		_rotationSpeed = cg::Properties::instance()->getDouble("CAR_ROTATION_SPEED");
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
		_carRotation = 0;
		
		//The initial position: bottom left of the screen TODO: Should be on the config.ini
	//	_position[0] = 100;
	//	_position[1] = 100;
	}
	
	double Car::getRotationSpeed() 
	{
		cg::Vector2d min = _position - _size/2.0;
		return _rotationSpeed;
	}
	void Car::draw()
	{	
        glColor3d(0.2, 0.3, 0.4);
		glLineWidth(1);
        
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
            glTranslatef(_position[0],_position[1],0.0);
            glRotatef(_carRotation, 0.0, 0.0, 1.0);
            glTranslatef(-_position[0],-_position[1],0.0);
            glTranslatef(_position[0], _position[1], -400);
            glRotated(90, 1.0, 0.0, 0.0);
            glRotated(180, 0.0, 1.0, 0.0);
            glmDraw(model,GLM_MATERIAL|GLM_SMOOTH);
		glPopMatrix();
	}

	void Car::update(unsigned long elapsed_millis)
	{


		double time = (double) elapsed_millis;

		if (_velocity[1] < -_maxSpeed)
			_velocity[1] = -_maxSpeed;
		else if (_velocity[1] > _maxSpeed)
			_velocity[1] = _maxSpeed;
	
		printf("%f - %f -> %f \n", _position[0] , _position[1], _carRotation);
		
		_acceleration[1] = _appForce[1]/_mass;
		_velocity[0] += _appForce[0]*time;	//turning velocity
		_velocity[1] += _acceleration[1]*time;
		
		/**************************************************************************/
		if (_appForce[1] >= 0 && _velocity[1] > 0 && _arrowKeyPressed[1] == 0)
			_appForce[1] = -_movForce;

		else if (_appForce[1] <= 0 && _velocity[1] < 0 && _arrowKeyPressed[1] == 0)
			_appForce[1] = _movForce;


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
		
	//	if (_appForce[0] == 0)
	//		_velocity[0] = 0;
			
		_carRotation = _velocity[0];
		//_position[0] = _velocity[0]*time;//_rotationSpeed[0]*time; //_velocity[0]*time + (_acceleration[0]*time*time)/2;
		_position[1] += _velocity[1]*time + (_acceleration[1]*time*time)/2;
	}

	void Car::applyForce(cg::Vector2d force)
	{
		_appForce = force;
	}

	void Car::keyBreak(int direction) //TODO devia estar no controller.cpp
	{

		switch (direction) {
		case 1: //LEFT
			_appForce[0] = 0;
		//	_velocity[0] = 0;
			break;
		case 2: //UP
			_appForce[1] = -_movForce;
			_arrowKeyPressed[1] -= 1;
			break;
		case 3: //RIGHT
			_appForce[0] = 0;
			//_velocity[0] = 0;
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
