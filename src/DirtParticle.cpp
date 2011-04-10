/*
 * DirtParticle.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DirtParticle.h"

namespace Micromachines {

	DirtParticle::DirtParticle(std::string id, cg::Vector3d color, cg::Vector3d velocity) : Particle(id)
	{
		Particle::setColor(color);
		Particle::setVelocity(velocity);
		Particle::setMass(cg::Properties::instance()->getDouble("DIRT_PARTICLE_MASS"));
		_color = color;
		_velocity = velocity;
	}

	DirtParticle::~DirtParticle()
	{
	}


	void DirtParticle::init()
	{
		// Read from ini file
		double min_size = cg::Properties::instance()->getDouble("MIN_DIRT_SIZE");
		double max_size = cg::Properties::instance()->getDouble("MAX_DIRT_SIZE");
		// Creates DirtParticle
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_winWidth = win.width;
		_winHeight = win.height;
		_car = (Car*) cg::Registry::instance()->get("Car");
		_position = _car->getPosition();
		Particle::setSize(cg::Vector3d(Particle::randomBetween(min_size, max_size), Particle::randomBetween(min_size, max_size), Particle::randomBetween(min_size, max_size)));
	}


	void DirtParticle::update(unsigned long elapsed_millis)
	{
		double time = (elapsed_millis / 1000.0);
		_velocity[2] += -G*time;
		_position[2] += _velocity[2] * time - (G*time*time)/2;
		_position[0] += _velocity[0]*time;
		_position[1] += _velocity[1]*time;
		Particle::setPosition(_position);
	//	printf("%f - %f - %f\n", _position[0], _position[1], _position[2]);
		if (_position[2] < -420 && !_car->getVelocity()>0.01) {
			_velocity[2] = 50;
			_position = _car->getPosition();
			_velocity[0] = Particle::randomBetween(-50*(cos(_car->getRotation()*PI/180 + PI/2))-10,
							       -50*(cos(_car->getRotation()*PI/180 + PI/2))+10) ; // x direction
			_velocity[1] = Particle::randomBetween(-50*(sin(_car->getRotation()*PI/180 + PI/2))-10,
							       -50*(sin(_car->getRotation()*PI/180 + PI/2))+10); // y direction
			_position[0] = Particle::randomBetween(_position[0]-3, _position[0]+3);
			_position[1] = Particle::randomBetween(_position[1]-2, _position[1]+2);
			_position[2] = -405// Particle::randomBetween(_position[2]-4, _position[2]-8);
			Particle::setPosition(_position);
		} //else if (_position[2] < 405 && _car->getV
		//printf("position %f\n", _position[2]);
		//printf("_velocity[2] %f\n", _velocity[2]);
	}
	
}

