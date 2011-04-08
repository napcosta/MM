//
//  TrackManager.h
//  cglib
//
//  Created by Inês on 3/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TRACK_MANAGER
#define TRACK_MANAGER

#include "cg.h"
#include "TrackPiece.h"
#include "Room.h"
#include <vector>

namespace Micromachines {
	class TrackManager : public cg::Group,
	public cg::GroupDraw {
	private:
		int _floorSize, _countTracks;
		std::vector<std::vector<int> > _floor;
	    
		void addTrack(int _type, double posX, double posY);
		std::vector<int> posToMatrix(double posX, double posY);
	    
	protected:
		void createEntities();
        
	public:
		TrackManager(std::string name, int fllorSize);
		~TrackManager();
	};
}

#endif