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
		int _life;
		int _player;
		int _powerUp;
                 
		GLMmodel *model;

	public:
		Car(std::string id, int player);
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
		int getLife();
		int getPowerUp();
		void incPowerUp();
		bool isCollision(cg::Vector3d pos, cg::Vector2d size);
		void decreaseLife();
		void setMovForce(double force);
		void setVelocity(double velocity);
		double getAppForce();
		void positionSecondPlayer(cg::Vector3d position, double rotation);
	};

}

#endif /* Car_H_ */
