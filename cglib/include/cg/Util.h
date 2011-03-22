// This file is part of CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2007 Carlos Martinho
// Updated 2010 by J M Brisson Lopes (Mac OS X support)


#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <sys/timeb.h>
#include <vector>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Singleton.h"
#include "Vector.h"

namespace cg {

	/** cg::Util is a singleton providing a set of utility methods.
	 */
    class Util {

	SINGLETON_HEADER(Util)

	private:
		double projectionDistance(double minA, double maxA, double minB, double maxB);

    public:
        void drawBitmapString(std::string s, GLdouble x, GLdouble y);
        void drawBitmapStringVector(std::vector<std::string> s, GLdouble x, GLdouble y, GLdouble delta = -10);
        unsigned long getSystemTime();
        void worldToScreenCoordinates(GLdouble wx, GLdouble wy, GLdouble wz, GLdouble *sx, GLdouble *sy, GLdouble *sz);
        void screenToWorldCoordinates(GLdouble sx, GLdouble sy, GLdouble sz, GLdouble *wx, GLdouble *wy, GLdouble *wz);
		bool isPointInPolygon(const Vector2d& point, std::vector<Vector2d>& polygon);
		bool isAABBoxCollision(const Vector2d& bottomleft0, const Vector2d& topright0, 
							   const Vector2d& bottomleft1, const Vector2d& topright1);
    };

}

#endif // UTIL_H
