/*
 * DirtParticleManager.cpp
 *
 *  Created on: Jul 22, 2010
 *      Author: pinto
 */

#include "DirtParticleManager.h"

namespace Micromachines
	{

	DirtParticleManager::DirtParticleManager(std::string id) : cg::Entity(id)
	{
	}

	DirtParticleManager::~DirtParticleManager()
	{
		for (tDirtParticleIterator i = _DirtParticles.begin(); i != _DirtParticles.end(); i++) {
			delete (*i);
		}
	}

	void DirtParticleManager::init()
	{
		_car = (Car*) cg::Registry::instance()->get("Car");
		_position = cg::Vector3d(0, 200, -300); //_car->getPosition();
		_size = cg::Vector3d(100, 100, 100);
		_color = cg::Vector3d(0.0, 1.0, 1.0);
		_velocity = cg::Vector3d(0,0, 0);
		cg::Vector3d tmp = _car->getPosition();
		int nDirtParticle = cg::Properties::instance()->getInt("NDIRTPARTICLE");
		for (int i=0; i < nDirtParticle; i++) {
			std::ostringstream os;
			os << "DirtParticle" << i;
			DirtParticle *dirtParticle = new DirtParticle(os.str(), _size, _position, _color, _velocity);
			dirtParticle->init();
			_DirtParticles.push_back(dirtParticle);
		}
	}

	void DirtParticleManager::update(unsigned long elapsed_millis)
	{
		for (tDirtParticleIterator i = _DirtParticles.begin(); i != _DirtParticles.end(); i++) {
			(*i)->update(elapsed_millis);
		}
	}

	void DirtParticleManager::draw()
	{
		for (tDirtParticleIterator i = _DirtParticles.begin(); i != _DirtParticles.end(); i++) {
			(*i)->draw();
		}
	}
}

