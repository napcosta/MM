//
//  ObstacleManager.h
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef OBSTACLE_MANAGER_H
#define OBSTACLE_MANAGER_H

#include "cg.h"
#include "Collidable.h"

namespace Micromachines {
	
	class CollisionManager;
	
	class ObstacleManager : public cg::Group,
                            public cg::GroupDraw,
                            public cg::GroupUpdate,
                            public cg::IDrawOverlayListener {
	private:
		std::string _obstacleMessage;
		std::vector<Collidable*> _obstacles;
		typedef std::vector<Collidable*>::iterator tObstacleIterator;
		CollisionManager* _cm;
                                
	protected:
		void createEntities();
		void postInit();
                                
	public:
		ObstacleManager(std::string id);
		~ObstacleManager();
		void drawOverlay();
		void draw();
		void update(unsigned long elapsed_millis);
		std::vector<Collidable*> getObstacles();
                                
	};
    
}

#endif
