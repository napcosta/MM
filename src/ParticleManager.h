/*
 * ParticleManager.h
 *
 *  Created on: Jul 22, 2010
 *      Author: pinto
 */

#ifndef PARTICLEMANAGER_H_
#define PARTICLEMANAGER_H_
#include "Particle.h"

namespace Micromachines {

	class ParticleManager : public cg::Entity,
				public cg::IDrawListener,
				public cg::IUpdateListener,
				public cg::IDrawOverlayListener {

	private:
		std::vector<Particle*> _particles;
		typedef std::vector<Particle*>::iterator tParticleIterator;
		std::string nparticleMessage;

	public:
		ParticleManager(std::string id);
		~ParticleManager();
		void init();
		void update(unsigned long elapsed_millis);
		void draw();
		void drawOverlay();
	};


}

#endif /* PARTICLEMANAGER_H_ */
