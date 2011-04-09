/*
 * DirtParticle.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef DirtParticle_H_
#define DirtParticle_H_
#include "cg.h"
#include "Particle.h"
namespace Micromachines {

	class DirtParticle : public Particle
	{

	private:
		cg::Vector3d _position, _size;
		cg::Vector3d _color;
		cg::Vector3d _velocity, _acceleration;
		double _winWidth, _winHeight;
		

		double randomBetween(double min, double max);

	public:
		DirtParticle(std::string id, cg::Vector3d size, cg::Vector3d position, cg::Vector3d color, cg::Vector3d velocity);
		~DirtParticle();
		void init();
		void reset(cg::Vector3d position);
		void update(unsigned long elapsed_millis);
	};

}

#endif /* DirtParticle_H_ */
