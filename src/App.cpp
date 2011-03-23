/*
 * App.cpp
 *
 *  Created on: Jul 20, 2010
 *      Author: pinto
 */

#include "App.h"
#include "BEVCamera.h"
#include "Particle.h"
#include "Car.h"

namespace Micromachines {

	App::App() : cg::Application("config.ini")
	{
	}

	App::~App()
	{
	}

	void App::createEntities()
	{
		addEntity(new BEVCamera());
		addEntity(new ParticleManager("ParticleMngr"));
		addEntity(new Car("Car"));
		addEntity(new Controller());
	}

}
