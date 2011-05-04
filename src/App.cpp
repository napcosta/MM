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
		//addEntity(new NearCamera());
		addEntity(new DoubleCamera());
		//addEntity(new ParticleManager("ParticleMngr"));
		
		addEntity(new PlayerManager());
		addEntity(new PowerUpManager("PowerUpManager"));
		addEntity(new Controller());
		
		addEntity(new TrackManager("TrackManager", 2020));
		addEntity(new HUD());
		addEntity(new ObstacleManager("OM"));
		addEntity(new CollisionManager());
		addEntity(new Lights());
	}

}
