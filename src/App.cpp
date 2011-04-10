/*
 * App.cpp
 *
 *  Created on: Jul 20, 2010
 *      Author: pinto
 */

#include "App.h"

namespace Micromachines {

	App::App() : cg::Application("config.ini")
	{
	}

	App::~App()
	{
	}

	void App::createEntities()
	{
		addEntity(new NearCamera());
		addEntity(new Lights());
		//addEntity(new ParticleManager("ParticleMngr"));
		addEntity(new DirtParticleManager("DirtParticleMngr"));
		addEntity(new Car("Car"));
		addEntity(new Controller());
		addEntity(new ObstacleManager("ObstacleManager"));
		addEntity(new TrackManager("TrackManager", 2020));
		addEntity(new HUD());
	}

}
