/*
 * App.h
 *
 *  Created on: Jul 20, 2010
 *      Author: pinto
 */

#ifndef APP_H_
#define APP_H_

#include "cg/cg.h"

#include "ParticleManager.h"
#include "Controller.h"

namespace Armageddon {

	class App : public cg::Application {
	public:
		App();
		~App();
		void createEntities();
	};
}

#endif /* APP_H_ */
