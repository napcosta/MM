//
//  ObstacleManager.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ObstacleManager.h"

namespace Micromachines {
    
	ObstacleManager::ObstacleManager(std::string id) : cg::Group(id) {
	}
	ObstacleManager::~ObstacleManager() {
	}
	void ObstacleManager::createEntities() {
		int nObstacles = cg::Properties::instance()->getInt("N_OBSTACLES");
        srand((unsigned)time(0));
		for(int i = 0; i < nObstacles; i++) {
			std::ostringstream os;
			os << "Obstacle" << i;
			add(new Obstacle(os.str()));
		}
	}
	void ObstacleManager::postInit() {
        std::ostringstream os;
        os << size() << " obstacles on screen.";
		_obstacleMessage = os.str();
	}
	void ObstacleManager::drawOverlay() {
		glColor3d(0.9,0.1,0.1);
		cg::Util::instance()->drawBitmapString(_obstacleMessage,10,10);
	}
}