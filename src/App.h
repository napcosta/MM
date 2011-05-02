/*
 * App.h
 *
 *  Created on: Jul 20, 2010
 *      Author: pinto
 */

#ifndef APP_H_
#define APP_H_

#include "cg.h"

#include "ParticleManager.h"
#include "PowerUpManager.h"
#include "DirtParticleManager.h"
#include "Controller.h"
#include "NearCamera.h"
#include "DoubleCamera.h"
#include "Particle.h"
#include "Car.h"
#include "ObstacleManager.h"
#include "TrackManager.h"
#include "Lights.h"
#include "Room.h"
#include "HUD.h"
#include "ReactiveObject.h"

namespace Micromachines {

	class App : public cg::Application {
	public:
		App();
		~App();
		void createEntities();
	};
}

#endif /* APP_H_ */
