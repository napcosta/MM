//
//  TrackManager.h
//  cglib
//
//  Created by Inês on 3/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TRACK_MANAGER
#define TRACK_MANAGER

#define BLOCK_TRACK_SIZE 108

#include "cg.h"
#include "TrackPiece.h"
#include "Room.h"
#include "Car.h"
#include <vector>

namespace Micromachines {
	class TrackManager : public cg::Group,
	public cg::GroupDraw, public cg::IUpdateListener {
	private:
		int _floorSize, _countTracks, _size;
		std::vector<std::vector<int> > _floor;
		Car *_car;
	    
		void addTrack(int _type, double posX, double posY);
		std::vector<int> posToMatrix(double posX, double posY);
		void trackType1(cg::Vector3d pos, int x, int y);
		void trackType2(cg::Vector3d pos, int x, int y);
		void trackType3(cg::Vector3d pos, int x, int y);
		void trackType4(cg::Vector3d pos, int x, int y);
		void trackType5(cg::Vector3d pos, int x, int y);
		void trackType6(cg::Vector3d pos, int x, int y);
		std::vector<int> range(int x, int y);
		double _ofTrackForce;
		double _onTrackForce;
		bool _ofTrack; 
	    
	protected:
		void createEntities();
        
	public:
		TrackManager(std::string name, int fllorSize);
		~TrackManager();
		void update(unsigned long elapsed_millis);
		int getTypeFromMatrix(int x, int y);
		bool isOfTrack();
	};
}

#endif
