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
		addEntity(new ParticleManager("ParticleMngr"));
		addEntity(new Car("Car"));
		addEntity(new Controller());
		addEntity(new ObstacleManager("ObstacleManager"));
		addEntity(new TrackManager("TrackManager"));
		addEntity(new Room()); //there should be a RoomManager where all the rooms would be!
		addEntity(new HUD());
        
	}

}
