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

		//add player1
		addEntity(new Car("Car", 1));
		Car *_car = (Car*)cg::Registry::instance()->get("Car");
		addEntity(new DirtParticleManager("DPM1", _car));
		
		//add Player2
	//	addEntity(new Car("Player2", 2));
	//	_car = (Car*)cg::Registry::instance()->get("Player2");
	//	addEntity(new DirtParticleManager("DPM2", _car));
		
		addEntity(new PowerUpManager("PowerUpManager"));
		addEntity(new Controller());
		//addEntity(new ObstacleManager("OM"));
		
		addEntity(new TrackManager("TrackManager", 2020));
		addEntity(new HUD());
		addEntity(new ObstacleManager("OM"));
		addEntity(new CollisionManager());
		addEntity(new Lights());
	}

}
