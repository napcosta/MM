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
#include "Controller.h"
#include "BEVCamera.h"
#include "Particle.h"
#include "Car.h"
#include "ObstacleManager.h"
#include "TrackManager.h"

namespace Micromachines {

	class App : public cg::Application {
	public:
		App();
		~App();
		void createEntities();
	};
}

#endif /* APP_H_ */
