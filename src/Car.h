/*
 * Car.h
 *
 *  Created on: Jul 25, 2010
 *      Author: pinto
 */

#ifndef Car_H_
#define Car_H_

#include <string>
#include <ctime>
#include <math.h>
#include "cg.h"
#include "glm.h"

#define PI 3.14159265

namespace Micromachines {

	class Car : public cg::Entity,
		    public cg::IDrawListener,
		    public cg::IUpdateListener {

	private:
		double _winHeight;
		cg::Vector3d _position;
		cg::Vector3d _size;
		cg::Vector2d _appForce;
		cg::Vector2d _acceleration;
		cg::Vector2d _arrowKeyPressed;
		double _velocity;
		double _rotationSpeed;
		double _carRotation;
		double _atrittionFactor;
		double _mass;
		double _maxSpeed;
		double _movForce;
		
		
                 
        GLMmodel *model;

	public:
		Car(std::string id);
		~Car();
		void init();
		void draw();
		void update(unsigned long elapsed_millis);
		void applyForce(cg::Vector2d force);
		void setArrowKeyPressed(cg::Vector2d val);
		double getRotationSpeed();
		double getRotation();
		double getMovForce();
		double getVelocity();
		cg::Vector3d getPosition();
		cg::Vector2d getArrowKeyPressed();
	};

}

#endif /* Car_H_ */
