/*
 * DirtParticle.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DirtParticle.h"
#include "Car.h"
#include "TrackManager.h"

namespace Micromachines {

	DirtParticle::DirtParticle(std::string id, cg::Vector3d color, cg::Vector3d velocity, Car* car) : Particle(id)
	{
		Particle::setColor(color);
		Particle::setVelocity(velocity);
		Particle::setMass(cg::Properties::instance()->getDouble("DIRT_PARTICLE_MASS"));
		_color = color;
		_velocity = velocity;
		_car = car;
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
		_trackManager = (TrackManager*) cg::Registry::instance()->get("TrackManager");
		_position = _car->getPosition();
		_position[2] = -420;
		Particle::setSize(cg::Vector3d(Particle::randomBetween(min_size, max_size), Particle::randomBetween(min_size, max_size), Particle::randomBetween(min_size, max_size)));
	}
	
	


	void DirtParticle::update(unsigned long elapsed_millis)
	{
			double time = (elapsed_millis / 1000.0);
			cg::Vector2d carKeyPressed = _car->getArrowKeyPressed();
		
			_velocity[2] += -G*time;
			_position[2] += _velocity[2] * time - (G*time*time)/2;
			_position[0] += _velocity[0]*time;
			_position[1] += _velocity[1]*time;
			Particle::setPosition(_position);
			if (_position[2] < -405) { // If the particle drops below the ground, this will replace the particle in it's propper place
				_velocity[2] = Particle::randomBetween(45,55);
				_position = _car->getPosition();
				_velocity[0] = Particle::randomBetween(-50*(cos(_car->getRotation()*PI/180 + PI/2))-10,
								       -50*(cos(_car->getRotation()*PI/180 + PI/2))+10) ; // x direction
				_velocity[1] = Particle::randomBetween(-50*(sin(_car->getRotation()*PI/180 + PI/2))-10,
								       -50*(sin(_car->getRotation()*PI/180 + PI/2))+10); // y direction
				_position[2] = -400;
				_position[0] = Particle::randomBetween(_position[0]-4, _position[0]+4);
				_position[1] = Particle::randomBetween(_position[1]-4, _position[1]+4);
				
				/* If the speed drops, I want less and less particles to become visible on screen.
				   I will select particles not to be drawn randomly when the speed drops */
				/* To do that, as soon as the car gets of track, all particles should be visible,
				   and only then it randomly selects the particles not to be drawn as the speed drops */
				if (carKeyPressed[1] == 0 && _trackManager->isOfTrack() == true) {
					Particle::setDRAW(true);
					if(_car->getVelocity()*80 < randomBetween(1, 10)) {
						Particle::setDRAW(false);
					}
				} else if (carKeyPressed[1] == 1 && _trackManager->isOfTrack() == true) { // If the car accelerates, all particles should be visible
					Particle::setDRAW(true);
				} else if (_trackManager->isOfTrack() == false) { // If the car gets of track, no particle should be visible
					Particle::setDRAW(false);
				}
				Particle::setPosition(_position);
		}
	}
}

