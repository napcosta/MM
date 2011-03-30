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

namespace Micromachines {
    class TrackManager : public cg::Group,
    public cg::GroupDraw {
    private:
        
    protected:
		void createEntities();
        
    public:
        TrackManager(std::string name);
        ~TrackManager();
    };
}

#endif