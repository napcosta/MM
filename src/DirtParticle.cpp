/*
 * DirtParticle.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DirtParticle.h"

namespace Micromachines {

	DirtParticle::DirtParticle(std::string id, cg::Vector3d size, cg::Vector3d position, cg::Vector3d color, cg::Vector3d velocity) : Particle(id)
	{
		
		Particle::setSize(size);
		Particle::setPosition(position);
		Particle::setColor(color);
		Particle::setVelocity(velocity);
		Particle::setMass(cg::Properties::instance()->getDouble("DIRT_PARTICLE_MASS"));
		_size = size;
		_position = position;
		_color = color;
		_velocity = velocity;
	}

	DirtParticle::~DirtParticle()
	{
	}

	double DirtParticle::randomBetween(double min, double max)
	{
		return (rand() / (double)RAND_MAX * (max-min)) + min;
	}

	void DirtParticle::init()
	{
		// Read from ini file
		double min_size = cg::Properties::instance()->getDouble("MIN_SIZE");
		double max_size = cg::Properties::instance()->getDouble("MAX_SIZE");
		// Creates DirtParticle
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_winWidth = win.width;
		_winHeight = win.height;

	}


	void DirtParticle::update(unsigned long elapsed_millis)
	{
		double time = (elapsed_millis / 1000.0);
		_velocity[2] += G*time;
		_position[2] += -(_velocity[2] * time + (G*time*time)/2);
		printf("%f - %f\n", _position[2], _velocity[2]);
		Particle::setPosition(_position);
		if (_position[2] < -405) {
			_velocity[2] = 0;
			_position[2] = -300;
			Particle::setPosition(_position);
		}
		//printf("position %f\n", _position[2]);
		//printf("_velocity[2] %f\n", _velocity[2]);
	}
	
}

