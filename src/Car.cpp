/*
 * Car.cpp
 *
 *  Created on: Jul 25, 2010
 *      Author: pinto
 */

//TODO: Code must be cleaned. Most of it belongs in Controller.cpp and PhysicalEntity.cpp
// and the .ini file should be updated with the physical parameters for the matter.

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
		_life = cg::Properties::instance()->getInt("CAR_MAX_LIFE");
		
		
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		_velocity = 0.0;
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
		_carRotation = -90;
		_position[2] = -396;
		_position[0] = -4;
		_position[1] = -113;
		

	}
	
	double Car::getRotationSpeed() 
	{
		return _rotationSpeed;
	}
	
	double Car::getMovForce()
	{
		return _movForce;
	}
	
	void Car::setMovForce(double force)
	{
		_movForce = force;
	}
	
//	void Car::setRotationSpeed(int rotSpeed)
//	{
//		_rotationSpeed = rotSpeed;
//	}
	
	void Car::draw()
	{	
        	glColor3d(0.0, 0.0, 80.0);
		glLineWidth(1);        
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glTranslatef(_position[0],_position[1]-_size[0]*0.75,0.0);
		    	glRotatef(_carRotation, 0.0, 0.0, 1.0);
		    	glTranslatef(-_position[0],-_position[1]+_size[0]*0.75,0.0);
		    	glTranslatef(_position[0], _position[1], -396);//-396
		    	glRotated(90, 1.0, 0.0, 0.0);
		    	glRotated(180, 0.0, 1.0, 0.0);
		    	glmDraw(model,GLM_MATERIAL|GLM_SMOOTH);
		glPopMatrix();
	}

	void Car::update(unsigned long elapsed_millis)
	{

		double time = (double) elapsed_millis;
		
		if (_velocity < -_maxSpeed)
			_velocity = -_maxSpeed;
		else if (_velocity > _maxSpeed)
			_velocity = _maxSpeed;
			
		
		_acceleration[1] = _appForce[1]/_mass ;
		_velocity += _acceleration[1]*time - _velocity*_movForce;
		
		if (_appForce[1] >= 0 && _velocity > 0 && _arrowKeyPressed[1] == 0)
			_appForce[1] = -_movForce/2;

		else if (_appForce[1] <= 0 && _velocity < 0 && _arrowKeyPressed[1] == 0)
			_appForce[1] = _movForce/2;

		/* UGLY HACK!! This prevents the arrow keys from not doing the turning
		 * To reproduce the bug: While the car is deaccelerating quickly press
		 * left (and let go), right (and keep it pressed) then press up */
		if (_arrowKeyPressed[0] == 0)
			_appForce[0] = 0;
		else if (_arrowKeyPressed[0] == 1)
			_appForce[0] = -1;
		else if (_arrowKeyPressed[0] == -1)
			_appForce[0] = 1;
		/*********************************************************************/
		
		if (_appForce[1] > 0 && _velocity<0) {
			if (_velocity>=-0.0007 && _arrowKeyPressed[1] != 1) {
				_velocity=0;
				_appForce[1]=0;
				_acceleration[1]=0;
			}
		} else if (_appForce[1] < 0 && _velocity>0) {
			if (_velocity<=0.0007 && _arrowKeyPressed[1] != -1) {
				_velocity=0;
				_appForce[1]=0;
				_acceleration[1]=0;
			}
		}
		
		if (_velocity < -0.03)
			_velocity = -0.03; 
		
			
		if (_velocity != 0) //
			_carRotation += _appForce[0]; // BAD LAZY PROGRAMMING: _appForce, in this case, is the car rotation speed
		_position[0] += cos(_carRotation * PI/180 + PI/2) * (_velocity*time + (_acceleration[1]*time*time)/2);
		_position[1] += sin(_carRotation * PI/180 + PI/2) * (_velocity*time + (_acceleration[1]*time*time)/2);
	//	printf("%f - %f\n", _position[0], _position[1]);
	}

	void Car::applyForce(cg::Vector2d force)
	{
		_appForce = force;
	}
	
	double Car::getAppForce()
	{
		return _appForce[1];
	}

	cg::Vector2d Car::getArrowKeyPressed() {
		return _arrowKeyPressed;
	}

	void Car::setArrowKeyPressed(cg::Vector2d val)
	{
		_arrowKeyPressed = val;
	}
	
	cg::Vector3d Car::getPosition()
	{
		cg::Vector3d pos = _position;
		pos[1] -=_size[0]*0.75;	 //This is a workaround that has to do with the translation of the car...
		return pos;
	}
	
	double Car::getRotation()
	{
		return _carRotation;
	}
	
	double Car::getVelocity()
	{
		return _velocity;
	}
	
	void Car::setVelocity(double velocity)
	{
		_velocity = velocity;
	}
	
	int Car::getLife()
	{
		return _life;
	}
	
	bool Car::isCollision(cg::Vector3d pos, cg::Vector2d size)
	{
		return (_position[0] > pos[0]-size[0] && _position[0] < pos[0]+size[0] && _position[1] > pos[1]-size[1] && _position[1] < pos[1]+size[1]); 
	}
	
	void Car::decreaseLife()
	{	
		if (_life > 0)
			_life -= 10;
	}
}
