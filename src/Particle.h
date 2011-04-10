/*
 * Particle.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "cg.h"
#include <math.h>

#define G 270
namespace Micromachines {

	class Particle : public cg::Entity,
			 public cg::IDrawListener,
			 public cg::IUpdateListener
	{

	private:
		cg::Vector3d _position, _size;
		cg::Vector3d _color;
		cg::Vector3d _velocity;
		double _mass;
		double _winWidth, _winHeight;
		cg::Vector3d _acceleration;
		
	public:
		double GFORCE;
		double randomBetween(double min, double max);
		Particle(std::string id);
		~Particle();
		void init();
		void draw();
		void reset(cg::Vector3d position);
		void update(unsigned long elapsed_millis);
		void setSize(cg::Vector3d size);
		void setPosition(cg::Vector3d position);
		void setColor(cg::Vector3d color);
		void setVelocity(cg::Vector3d velocity);
		void setMass(double mass);
		cg::Vector3d getAcceleration();
	};

}

#endif /* PARTICLE_H_ */
