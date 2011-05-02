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
		addEntity(new DirtParticleManager("DirtParticleMngr"));
		addEntity(new PowerUpManager("PowerUpManager"));
		addEntity(new Car("Car"));
		addEntity(new Controller());
		//addEntity(new ObstacleManager("OM"));
		
		addEntity(new TrackManager("TrackManager", 2020));
		addEntity(new HUD());
		cg::Vector3d reactPos;
		reactPos[0] = -160;
		reactPos[1] = -52;
		reactPos[2] = -400;
		addEntity(new ReactiveObject(reactPos));
		addEntity(new Lights());
	}

}
