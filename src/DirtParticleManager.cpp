/*
 * DirtParticleManager.cpp
 *
 *  Created on: Jul 22, 2010
 *      Author: pinto
 */

#include "DirtParticleManager.h"

namespace Micromachines
	{

	DirtParticleManager::DirtParticleManager(std::string id, Car* car) : cg::Entity(id)
	{
		_car = car;
	}

	DirtParticleManager::~DirtParticleManager()
	{
		for (tDirtParticleIterator i = _DirtParticles.begin(); i != _DirtParticles.end(); i++) {
			delete (*i);
		}
	}

	void DirtParticleManager::init()
	{
		_color = cg::Vector3d(0.2, 0.13, 0.00);
		_velocity = cg::Vector3d(0,0, 0);
		int nDirtParticle = cg::Properties::instance()->getInt("NDIRTPARTICLE");
		for (int i=0; i < nDirtParticle; i++) {
			std::ostringstream os;
			os << "DirtParticle" << i;
			DirtParticle *dirtParticle = new DirtParticle(os.str(), _color, _velocity, _car);
			dirtParticle->init();
			_DirtParticles.push_back(dirtParticle);
		}
	}
	
		double DirtParticleManager::randomBetween(double min, double max)
	{
		return (rand() / (double)RAND_MAX * (max-min)) + min;
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

