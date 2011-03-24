//
//  Obstacle.h
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "cg.h"

namespace Micromachines {
    class Obstacle : public cg::Entity,
    public cg::IDrawListener,
    public cg::IUpdateListener{
    private:
        cg::Vector3d _position, _color;
        double _winHeight, _winWidth;
        int _type;
        
        int RandomBeetween(int min, int max);
        void drawCircle();
        void drawRectangle();
        void drawTriangle();
        
    public:
        Obstacle(std::string name);
        ~Obstacle();
        void init();
        void draw();
        void update(unsigned long elapsed_millis);
    };
}

#endif