/*
 * DirtParticleManager.h
 *
 *  Created on: Jul 22, 2010
 *      Author: pinto
 */

#ifndef DirtParticleMANAGER_H_
#define DirtParticleMANAGER_H_
#include "DirtParticle.h"
#include "Car.h"

namespace Micromachines {

	class DirtParticleManager : public cg::Entity,
				public cg::IDrawListener,
				public cg::IUpdateListener {

	private:
		std::vector<DirtParticle*> _DirtParticles;
		typedef std::vector<DirtParticle*>::iterator tDirtParticleIterator;
		std::string nDirtParticleMessage;
		cg::Vector3d _size;
		cg::Vector3d _position;
		cg::Vector3d _color;
		cg::Vector3d _velocity;
		Car* _car;
		

	public:
		DirtParticleManager(std::string id);
		~DirtParticleManager();
		void init();
		void update(unsigned long elapsed_millis);
		void draw();
		double randomBetween(double min, double max);
	};


}

#endif /* DirtParticleMANAGER_H_ */
