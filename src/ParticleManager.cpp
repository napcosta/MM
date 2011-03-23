/*
 * ParticleManager.cpp
 *
 *  Created on: Jul 22, 2010
 *      Author: pinto
 */

#include "ParticleManager.h"

namespace Micromachines
	{

	ParticleManager::ParticleManager(std::string id) : cg::Entity(id)
	{
	}

	ParticleManager::~ParticleManager()
	{
		for (tParticleIterator i = _particles.begin(); i != _particles.end(); i++) {
			delete (*i);
		}
	}

	void ParticleManager::init()
	{
		int nParticle = cg::Properties::instance()->getInt("NPARTICLE");
		for (int i=0; i < nParticle; i++) {
			std::ostringstream os;
			os << "Particle" << i;
			Particle *particle = new Particle(os.str());
			particle->init();
			_particles.push_back(particle);
		}
	}

	void ParticleManager::update(unsigned long elapsed_millis)
	{
		for (tParticleIterator i = _particles.begin(); i != _particles.end(); i++) {
			(*i)->update(elapsed_millis);
		}
	}

	void ParticleManager::draw()
	{
		for (tParticleIterator i = _particles.begin(); i != _particles.end(); i++) {
			(*i)->draw();
		}
	}

	void ParticleManager::drawOverlay()
	{
		glColor3d(0.9, 0.1, 0.1);
		cg::Util::instance()->drawBitmapString(nparticleMessage,10,10);
	}
}

