//
//  TrackPiece.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TrackPiece.h"

namespace Micromachines {
    
    /******************************/
    /*            Type 1           */
    /*******************************/
    /*                             */
    /*         |           |       */
    /*         |           |       */
    /*         |           |       */
    /*         |           |       */
    /*         |           |       */
    /*         |           |       */
    /*         |           |       */
    /*         |           |       */
    /*                             */
    /*******************************/
    
    void TrackPiece::drawType1(){
        glBegin(GL_LINES);
            glVertex3d(27, 0, -400);
            glVertex3d(27, 108, -400);
            glVertex3d(81, 0, -400);
            glVertex3d(81, 108, -400);
        glEnd();
    }
    
    /******************************/
    /*            Type 4           */
    /*******************************/
    /*                             */
    /*      |         |            */
    /*       \         \           */
    /*        \         \          */
    /*         \         \         */
    /*          \         \_       */
    /*           \                 */
    /*            \                */
    /*             \________       */
    /*                             */
    /*******************************/
    
    void TrackPiece::drawType4(){
        glBegin(GL_LINE_STRIP);
            glVertex3d(27, 108, -400);
            glVertex3d(27, 99, -400);
            glVertex3d(45, 63, -400);
            glVertex3d(63, 45, -400);
            glVertex3d(99, 27, -400);
            glVertex3d(108, 27, -400);
        glEnd();
        
        glBegin(GL_LINE_STRIP);
            glVertex3d(81, 108, -400);
            glVertex3d(81, 99, -400);
            glVertex3d(99, 81, -400);
            glVertex3d(108, 81, -400);
        glEnd();
    }
    
    void TrackPiece::drawType3(){}
    
    void TrackPiece::drawType2(){}
    
    void TrackPiece::drawType5(){}
    
    void TrackPiece::drawType6(){}
    
    TrackPiece::TrackPiece(std::string name, int type, int direction) : cg::Entity(name){
        _type = type;
        _direction = direction;
    }
    
    TrackPiece::~TrackPiece(){}
    
    void TrackPiece::init(){}
    
    void TrackPiece::draw(){
        glColor3d(1, 0, 0);
        glLineWidth(1.5);
        drawType2();
    }
}