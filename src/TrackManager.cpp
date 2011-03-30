//
//  TrackManager.cpp
//  cglib
//
//  Created by Inês on 3/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TrackManager.h"

namespace Micromachines {
    
    TrackManager::TrackManager(std::string name) : cg::Group(name){}
    
    TrackManager::~TrackManager(){}
    
    void TrackManager::createEntities(){
        add(new TrackPiece("Track1", 4 ,cg::Vector2d(100.0, 100.0)));
        add(new TrackPiece("Track2", 1 ,cg::Vector2d(100.0, 208.0)));
        add(new TrackPiece("Track3", 1 ,cg::Vector2d(100.0, 316.0)));
        add(new TrackPiece("Track4", 2 ,cg::Vector2d(100.0, 424.0)));
        add(new TrackPiece("Track15", 3 ,cg::Vector2d(208.0, 424.0)));
        add(new TrackPiece("Track5", 4 ,cg::Vector2d(208.0, 316.0)));
        add(new TrackPiece("Track6", 5 ,cg::Vector2d(316.0, 316.0)));
        add(new TrackPiece("Track7", 2 ,cg::Vector2d(316.0, 424.0)));
        add(new TrackPiece("Track16", 6 ,cg::Vector2d(424.0, 424.0)));
        add(new TrackPiece("Track8", 3 ,cg::Vector2d(532.0, 424.0)));
        add(new TrackPiece("Track9", 1 ,cg::Vector2d(532.0, 316.0)));
        add(new TrackPiece("Track10", 1 ,cg::Vector2d(532.0, 208.0)));
        add(new TrackPiece("Track11", 5 ,cg::Vector2d(532.0, 100.0)));
        add(new TrackPiece("Track12", 6 ,cg::Vector2d(424.0, 100.0)));
        add(new TrackPiece("Track13", 6 ,cg::Vector2d(316.0, 100.0)));
        add(new TrackPiece("Track14", 6 ,cg::Vector2d(208.0, 100.0)));
    }
    
}
