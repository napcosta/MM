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
		if((_floorSize)%BLOCK_TRACK_SIZE == 0)
			_size = floorSize/BLOCK_TRACK_SIZE;
		else _size = floorSize/BLOCK_TRACK_SIZE+1;
		_floor = std::vector<std::vector<int> >(_size, std::vector<int>(_size, 0));
		_car = (Car*) cg::Registry::instance()->get("Car");
		_ofTrack = false;
		_ofTrackForce = cg::Properties::instance()->getDouble("CAR_OUT_OF_TRACK_FORCE");
		_onTrackForce = cg::Properties::instance()->getDouble("CAR_MOV_FORCE");
	}
    
	TrackManager::~TrackManager(){}
	
	bool TrackManager::isOfTrack() 
	{
		return _ofTrack;
	}
    
	void TrackManager::createEntities(){
		add(new Room(_floorSize));
		
		addTrack(4, 8, 11);
		addTrack(1, 8, 10);
		addTrack(1, 8, 9);
		addTrack(2, 8, 8);
		addTrack(3, 9, 8);
		addTrack(4, 9, 9);
		addTrack(5, 10, 9);
		addTrack(2, 10, 8);
		addTrack(6, 11, 8);
		addTrack(3, 12, 8);
		addTrack(1, 12, 9);
		addTrack(1, 12, 10);
		addTrack(5, 12, 11);
		addTrack(6, 11, 11);
		addTrack(6, 10, 11);
		addTrack(6, 9, 11);
		
		int i, j;
		for(i=0;i < _size;i++){
			for (j = 0; j<_size; j++) {
				std::cout << _floor[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	std::vector<int> TrackManager::posToMatrix(double posX, double posY)
	{
		std::vector<int> pos(2);
		
		
		pos[1] = (((_floorSize/2)+posX)*_size)/_floorSize;
		pos[0] = _size - ((((_floorSize/2)+posY)*(_size)/_floorSize)-1);
		
		return pos;
	}
	
	void TrackManager::addTrack(int _type, double posX, double posY)
	{
		std::string s;
		std::stringstream os;
		os << "Track" << _countTracks;
		_countTracks++;
		
		s = os.str();
		
		_floor[posY][posX] = _type;
		
		std::vector<int> ranges = range(posY, posX);

		add(new TrackPiece(s, _type, cg::Vector2d(((ranges[1]-ranges[0])/2)+ranges[0], ((ranges[3]-ranges[2])/2)+ranges[2])));
	}
	
	int TrackManager::getTypeFromMatrix(int x, int y)
	{
		return _floor[x][y];
	}
	
	std::vector<int> TrackManager::range(int x, int y)
	{
		std::vector<int> range(4);
		
		range[2] = (_floorSize/2)-(x*_floorSize/_size);
		range[3] = range[2] + BLOCK_TRACK_SIZE;
		range[0] = (y*_floorSize/_size)-(_floorSize/2);
		range[1] = range[0] + BLOCK_TRACK_SIZE;
		
		return range;
	}
	
	void TrackManager::trackType1(cg::Vector3d pos, int x, int y)
	{
		std::vector<int> ranges = range(x, y);
		
		if (pos[0] < ranges[0]+ 27 || pos[0] > ranges[1] - 27){
		//	std::cout << "Estou fora" << std::endl;
			_ofTrack = true;
			_car->setMovForce(_ofTrackForce);
		} else { 
		//	std::cout << "Estou dentro" << std::endl;
			_ofTrack = false;
			_car->setMovForce(_onTrackForce);
		}
	}
	
	void TrackManager::trackType2(cg::Vector3d pos, int x, int y)
	{
		std::vector<int> ranges = range(x, y);
		
		double m1 = (double)(ranges[3]-ranges[2])/(ranges[1]-ranges[0]);
		double b1 = ranges[2] - m1 * ranges[0];
		
		double m2 = (double)((ranges[2]+45)-(ranges[2]+9))/((ranges[0]+45)-(ranges[0]+27));
		double b2 = (ranges[2]+9) - m2*(ranges[0]+27);
		
		double m3 = (double)((ranges[2]+63)-(ranges[2]+81))/((ranges[0]+63)-(ranges[0]+99));
		double b3 = (ranges[2]+63) - m3*(ranges[0]+63);
		
		double m4 = (double)((ranges[2]+9)-(ranges[2]+27))/((ranges[0]+81)-(ranges[0]+99));
		double b4 = (ranges[2]+9) - m4*(ranges[0]+81);
		
		if ((pos[0] < ranges[0]+ 27) || (pos[1] > ranges[3] - 27) || (pos[1] > pos[0]*m1 + b1) ||
		    (pos[1] > pos[0]*m2 + b2) || (pos[1] > pos[0]*m3+b3) || ((pos[1] < pos[0]*m4+b4) && 
		    (pos[0] > ranges[1] - 27) && (pos[1] < ranges[2] + 27))) {
		//	std::cout << "Estou fora" << std::endl;
			_ofTrack = true;
			_car->setMovForce(_ofTrackForce);
		} else {
		//	std::cout << "Estou dentro" << std::endl;
			_ofTrack = false;
			_car->setMovForce(_onTrackForce);
		}
	}
	
	void TrackManager::trackType3(cg::Vector3d pos, int x, int y)
	{
		std::vector<int> ranges = range(x,y);
		
		double m1 = (double)(ranges[2]-ranges[3])/(ranges[1]-ranges[0]);
		double b1 = ranges[2] - m1 * ranges[0];
		
		double m2 = (double)((ranges[3]-27)-(ranges[3]-45))/((ranges[0]+9)-(ranges[0]+45));
		double b2 = (ranges[3]-45) - m2*(ranges[0]+45);
		
		double m3 = (double)((ranges[2]+9)-(ranges[2]+45))/((ranges[1]-27)-(ranges[1]-45));
		double b3 = (ranges[2]+45) - m3*(ranges[1]-45);
		
		double m4 = (double)((ranges[2]+9)-(ranges[2]+27))/((ranges[0]+27)-(ranges[0]+9));
		double b4 = (ranges[2]+9) - m4*(ranges[0]+27);
		
		if ((pos[0] > ranges[1]-27) || (pos[1] > ranges[3] - 27) || (pos[1] < pos[0]*m1 + b1) ||
		    (pos[1] > pos[0]*m2 + b2) || (pos[1] > pos[0]*m3+b3) || ((pos[1] < pos[0]*m4+b4) &&
		    (pos[0] > ranges[0] + 27) && (pos[1] < ranges[2] + 27))) {
		//	std::cout << "Estou fora" << std::endl;
			_ofTrack = true;
			_car->setMovForce(_ofTrackForce);
		} else { 
		//	std::cout << "Estou dentro" << std::endl;
			_ofTrack = false;
			_car->setMovForce(_onTrackForce);
		}
		
	}
	
	void TrackManager::trackType4(cg::Vector3d pos, int x, int y)
	{
		std::vector<int> ranges = range(x,y);
		
		double m1 = (double)(ranges[2]-ranges[3])/(ranges[1]-ranges[0]);
		double b1 = ranges[2] - m1 * ranges[0];
		
		double m2 = (double)((ranges[3]-27)-(ranges[3]-45))/((ranges[0]+9)-(ranges[0]+45));
		double b2 = (ranges[3]-45) - m2*(ranges[0]+45);
		
		double m3 = (double)((ranges[2]+27)-(ranges[2]+45))/((ranges[1]-9)-(ranges[1]-45));
		double b3 = (ranges[2]+45) - m3*(ranges[1]-45);
		
		double m4 = (double)((ranges[3]-27)-(ranges[3]-9))/((ranges[1]-9)-(ranges[1]-27));
		double b4 = (ranges[3]-9) - m4*(ranges[1]-27);
		
		if ((pos[0] < ranges[0]+27) || (pos[1] < ranges[2] + 27) || (pos[1] < pos[0]*m1 + b1) ||
		    (pos[1] < pos[0]*m2 + b2) || (pos[1] < pos[0]*m3+b3) || ((pos[1] > pos[0]*m4+b4) &&
		    (pos[0] > ranges[0] + 27) && (pos[1] > ranges[2] + 27))) {
		//	std::cout << "Estou fora" << std::endl;
			_ofTrack = true;
			_car->setMovForce(_ofTrackForce);
		} else { 
		//	std::cout << "Estou dentro" << std::endl;
			_ofTrack = false;
			_car->setMovForce(_onTrackForce);
		}
		
	}
	
	void TrackManager::trackType5(cg::Vector3d pos, int x, int y)
	{
		std::vector<int> ranges = range(x,y);
		
		double m1 = (double)(ranges[2]-ranges[3])/(ranges[1]-ranges[0]);
		double b1 = ranges[2] - m1 * ranges[0];
		
		double m2 = (double)((ranges[2]+45)-(ranges[2]+27))/((ranges[0]+45)-(ranges[0]+9));
		double b2 = (ranges[2]+45) - m2*(ranges[0]+45);
		
		double m3 = (double)((ranges[3]-9)-(ranges[3]-45))/((ranges[1]-27)-(ranges[1]-45));
		double b3 = (ranges[3]-45) - m3*(ranges[1]-45);
		
		double m4 = (double)((ranges[3]-9)-(ranges[3]-27))/((ranges[0]+27)-(ranges[0]+9));
		double b4 = (ranges[3]-9) - m4*(ranges[0]+27);
		
		if ((pos[0] > ranges[1]-27) || (pos[1] < ranges[2] + 27) || (pos[1] < pos[0]*m1 + b1) ||
		    (pos[1] < pos[0]*m2 + b2) || (pos[1] < pos[0]*m3+b3) || ((pos[1] > pos[0]*m4+b4) && 
		    (pos[0] < ranges[0] + 27) && (pos[1] > ranges[3] - 27))) {
		//	std::cout << "Estou fora" << std::endl;
			_ofTrack = true;
			_car->setMovForce(_ofTrackForce);
		} else {
		//	std::cout << "Estou dentro" << std::endl;
			_ofTrack = false;
			_car->setMovForce(_onTrackForce);
		}
		
	}
	
	void TrackManager::trackType6(cg::Vector3d pos, int x, int y)
	{
		std::vector<int> ranges = range(x, y);
		
		if (pos[1] < ranges[2]+ 27 || pos[1] > ranges[3] - 27) {
		//	std::cout << "Estou fora" << std::endl;
			_ofTrack = true;
			_car->setMovForce(_ofTrackForce);
		} else { 
			//std::cout << "Estou dentro" << std::endl;
			_ofTrack = false;
			_car->setMovForce(_onTrackForce);
		}
	}
	
	void TrackManager::update(unsigned long elapsed_millis)
	{
		cg::Vector3d pos = _car->getPosition();
		std::vector<int> mat = posToMatrix(pos[0], pos[1]);
		
		int type = getTypeFromMatrix(mat[0], mat[1]);
		switch (type) {
				
			case 0:
				_ofTrack = true;
				_car->setMovForce(_ofTrackForce);
			//	std::cout << "Estou fora" << std::endl;
				break;
			case 1:
				trackType1(pos, mat[0], mat[1]);
				break;
				
			case 2:
				trackType2(pos, mat[0], mat[1]);
				break;
				
			case 3:
				trackType3(pos, mat[0], mat[1]);
				break;
			
			case 4:
				trackType4(pos, mat[0], mat[1]);
				break;
				
			case 5:
				trackType5(pos, mat[0], mat[1]);
				break;
				
			case 6:
				trackType6(pos, mat[0], mat[1]);
				break;
		}
	}
    
}
