//
//  TrackPiece.h
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TRACK_PIECE_H
#define TRACK_PIECE_H

#include "cg.h"

namespace Micromachines {
    class TrackPiece : public cg::Entity, public cg::IDrawListener{
    private:
        int _type, _direction;
        cg::Vector2d _position;
        
        void drawType1();
        void drawType2();
        void drawType3();
        void drawType4();
        void drawType5();
        void drawType6();
        
    public:
        TrackPiece(std::string name, int type, cg::Vector2d position);
        ~TrackPiece();
        
        void init();
        void draw();
        
    };
}

#endif