/*
 * Particle.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "cg/cg.h"
namespace Armageddon {

	class Particle : public cg::Entity,
			 public cg::IDrawListener,
			 public cg::IUpdateListener
	{

	private:
		cg::Vector3d _position, _size;
		cg::Vector3d _color;
		cg::Vector3d _velocity;
		double _winWidth, _winHeight;

		double randomBetween(double min, double max);

	public:
		Particle(std::string id);
		~Particle();
		void init();
		void draw();
		void reset(cg::Vector3d position);
		void update(unsigned long elapsed_millis);

	};

}

#endif /* PARTICLE_H_ */
