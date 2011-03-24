//
//  ObstacleManager.h
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef OBSTACLE_MANAGER_H
#define OBSTACLE_MANAGER_H

#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cg.h"
#include "Obstacle.h"

namespace Micromachines {
    
	class ObstacleManager : public cg::Group,
                            public cg::GroupDraw,
                            public cg::GroupUpdate,
                            public cg::IDrawOverlayListener {
	private:
		std::string _obstacleMessage;
                                
	protected:
		void createEntities();
		void postInit();
                                
	public:
		ObstacleManager(std::string id);
		~ObstacleManager();
		void drawOverlay();
                                
	};
    
}

#endif
