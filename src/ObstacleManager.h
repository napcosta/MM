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
#include "ReactiveObject.h"

namespace Micromachines {
    
	class ObstacleManager : public cg::Group,
                            public cg::GroupDraw,
                            public cg::GroupUpdate,
                            public cg::IDrawOverlayListener {
	private:
		std::string _obstacleMessage;
		std::vector<Obstacle*> _obstacles;
		std::vector<ReactiveObject*> _reactObstacles;
		typedef std::vector<Obstacle*>::iterator tObstacleIterator;
		typedef std::vector<ReactiveObject*>::iterator tReactObstaclesIterator;
                                
	protected:
		void createEntities();
		void postInit();
                                
	public:
		ObstacleManager(std::string id);
		~ObstacleManager();
		void drawOverlay();
		void draw();
		void update(unsigned long elapsed_millis);
		std::vector<Obstacle*> getObstacles();
		std::vector<ReactiveObject*> getReactObstacles();
                                
	};
    
}

#endif
