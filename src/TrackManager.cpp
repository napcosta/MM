//
//  TrackManager.cpp
//  cglib
//
//  Created by Inês on 3/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TrackManager.h"

namespace Micromachines {
    
	TrackManager::TrackManager(std::string name, int floorSize) : cg::Group(name)
	{
		_floorSize = floorSize;
		int size = floorSize/108;
		_floor = std::vector<std::vector<int> >(size, std::vector<int>(size, 0));

	}
    
	TrackManager::~TrackManager(){}
    
	void TrackManager::createEntities(){
		add(new Room(_floorSize));
		
		addTrack(4, 100.0, 100.0);
		addTrack(1, 100.0, 208.0);
		addTrack(1, 100.0, 316.0);
		addTrack(2, 100.0, 424.0);
		addTrack(3, 208.0, 424.0);
		addTrack(4, 208.0, 316.0);
		addTrack(5, 316.0, 316.0);
		addTrack(2, 316.0, 424.0);
		addTrack(6, 424.0, 424.0);
		addTrack(3, 532.0, 424.0);
		addTrack(1, 532.0, 316.0);
		addTrack(1, 532.0, 208.0);
		addTrack(5, 532.0, 100.0);
		addTrack(6, 424.0, 100.0);
		addTrack(6, 316.0, 100.0);
		addTrack(6, 208.0, 100.0);
		
		int i, j;
		for(i=0;i < _floorSize/108;i++){
			for (j = 0; j<_floorSize/108; j++) {
				std::cout << _floor[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	std::vector<int> TrackManager::posToMatrix(double posX, double posY)
	{
		std::vector<int> pos(2);
		
		
		pos[1] = (((_floorSize/2)+posX)*(_floorSize/108))/_floorSize;
		pos[0] = _floorSize/108 - (((((_floorSize/2)+posY)*(_floorSize/108))/_floorSize)-1);
		
		return pos;
	}
	
	void TrackManager::addTrack(int _type, double posX, double posY)
	{
		std::string s;
		std::stringstream os;
		os << "track" << _countTracks;
		_countTracks++;
		
		s = os.str();
		
		std::vector<int> pos(2);
		
		pos = posToMatrix(posX, posY);
		int x, y;
		x = pos[0];
		y = pos[1];
		
		_floor[x][y] = _type;
		std::cout << "x - " << pos[0] << " y - " << pos[1] << std::endl;
		add(new TrackPiece(s, _type, cg::Vector2d(posX, posY)));
	}
    
}
