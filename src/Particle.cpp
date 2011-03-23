/*
 * Particle.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "Particle.h"

namespace Micromachines {

	Particle::Particle(std::string id) : cg::Entity(id)
	{
	}

	Particle::~Particle()
	{
	}

	double Particle::randomBetween(double min, double max)
	{
		return (rand() / (double)RAND_MAX * (max-min)) + min;
	}

	void Particle::init()
	{
		// Read from ini file
		double min_size = cg::Properties::instance()->getDouble("MIN_SIZE");
		double max_size = cg::Properties::instance()->getDouble("MAX_SIZE");
		// Creates particle
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_winWidth = win.width;
		_winHeight = win.height;
		//_position = cg::Vector3d(_winWidth/2,_winHeight/2,0);
		//_size = cg::Vector3d(20,20,0);
		_position = cg::Vector3d(randomBetween(0, _winWidth), randomBetween(0, _winHeight), randomBetween(300,399));
		_size = cg::Vector3d(randomBetween(min_size, max_size), randomBetween(min_size, max_size),0);
		_color = cg::Vector3d(1,1,1);
		_velocity = cg::Vector3d(randomBetween(-10,10), randomBetween(30,60),0);

	}

	void Particle::draw()
	{
		cg::Vector3d min = _position - _size/100.0;
		cg::Vector3d max = _position + _size/100.0;
		glColor3dv(_color.get());
		//glLineWidth(1.5);
		glBegin(GL_POLYGON);
			glVertex3d(min[0], min[1], -400);
			glVertex3d(max[0], min[1], -400);
			glVertex3d(max[0], max[1], -400);
			glVertex3d(min[0], max[1], -400);
		//	glVertex3d(min[0], max[1]*2, 10);
		glEnd();
	}


	void Particle::update(unsigned long elapsed_millis)
	{
		double elapsed_seconds = elapsed_millis / 1000.0;
		_position -= _velocity * elapsed_seconds;
		if (_position[0] < 0) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(_winHeight, _winHeight);
		} if (_position[0] > _winWidth) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(_winHeight, _winHeight);
		} if (_position[1] < 0) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(_winHeight, _winHeight);
		} if (_position[1] > _winHeight) {
			_position[0] = randomBetween(0, _winWidth);
			_position[1] = randomBetween(_winHeight, _winHeight);
		}
	}

}

