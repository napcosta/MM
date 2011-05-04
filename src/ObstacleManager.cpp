//
//  ObstacleManager.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "ObstacleManager.h"
#include "Obstacle.h"
#include "ReactiveObject.h"
#include "CollisionManager.h"

namespace Micromachines {
    
	ObstacleManager::ObstacleManager(std::string id) : cg::Group(id) 
	{
	}
	ObstacleManager::~ObstacleManager() 
	{
	}
	void ObstacleManager::createEntities() {
		int nObstacles = cg::Properties::instance()->getInt("N_OBSTACLES");
		_cm = (CollisionManager*)cg::Registry::instance()->get("COLLISION_MANAGER");
		srand((unsigned)time(0));
		for(int i = 0; i < nObstacles; i++) {
			std::ostringstream os;
			os << "Obstacle" << i;
			Collidable *ob = new Obstacle(os.str());
			ob->init();
			_obstacles.push_back(ob);
		}
		cg::Vector3d reactPos;
		reactPos[0] = -160;
		reactPos[1] = -52;
		reactPos[2] = -400;
		Collidable *react = new ReactiveObject(reactPos);
		react->init();
		_obstacles.push_back(react);
		_cm->setObstacles(_obstacles);
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
	
	std::vector<Collidable*> ObstacleManager::getObstacles()
	{
		return _obstacles;
	}
	
	void ObstacleManager::draw()
	{
		for(tObstacleIterator i = _obstacles.begin(); i != _obstacles.end(); i++) {
			(*i)->draw();
		}
	}
	
	void ObstacleManager::update(unsigned long elapsed_millis)
	{
		for(tObstacleIterator i = _obstacles.begin(); i != _obstacles.end(); i++) {
			(*i)->update(elapsed_millis);
		}
	}
}
