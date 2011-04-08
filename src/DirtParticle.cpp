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
		double elapsed_seconds = elapsed_millis / 1000.0;
		_position -= _velocity * elapsed_seconds;
		if (_position[0] < 0) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(0, _winHeight);
			_position[2] = 0;
		} if (_position[0] > _winWidth) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(0, _winHeight);
			_position[2] = 0;
		} if (_position[1] < 0) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(0, _winHeight);
			_position[2] = 0;
		} if (_position[1] > _winHeight) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(0, _winHeight);
			_position[2] = 0;
		} if (_position[2] < -399) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(0, _winHeight);
			_position[2] = -250;
		}
	}
}

