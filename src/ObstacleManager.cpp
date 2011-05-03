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
			Obstacle *ob = new Obstacle(os.str());
			ob->init();
			_obstacles.push_back(ob);
		}
		cg::Vector3d reactPos;
		reactPos[0] = -160;
		reactPos[1] = -52;
		reactPos[2] = -400;
		ReactiveObject *react = new ReactiveObject(reactPos);
		react->init();
		_reactObstacles.push_back(react);
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
	
	std::vector<Obstacle*> ObstacleManager::getObstacles()
	{
		return _obstacles;
	}
	
	std::vector<ReactiveObject*> ObstacleManager::getReactObstacles()
	{
		return _reactObstacles;
	}
	
	void ObstacleManager::draw()
	{
		for(tObstacleIterator i = _obstacles.begin(); i != _obstacles.end(); i++) {
			(*i)->draw();
		}
		
		for(tReactObstaclesIterator i = _reactObstacles.begin(); i != _reactObstacles.end(); i++) {
			(*i)->draw();
		}
	}
	
	void ObstacleManager::update(unsigned long elapsed_millis)
	{
		for(tObstacleIterator i = _obstacles.begin(); i != _obstacles.end(); i++) {
			(*i)->update(elapsed_millis);
		}
		
		for(tReactObstaclesIterator i = _reactObstacles.begin(); i != _reactObstacles.end(); i++) {
			(*i)->update(elapsed_millis);
		}
	}
}
