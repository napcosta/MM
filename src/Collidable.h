/*
 * Collidable.h
 *
 *  Created on: May 4, 2011
 *      Author: pinto
 */

#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "cg.h"

namespace Micromachines {
	class Collidable : public cg::Entity, public cg::IDrawListener, public cg::IUpdateListener {
	public:
		Collidable(std::string id) : cg::Entity(id) {}
		~Collidable() {}
		virtual cg::Vector3d getPosition() = 0;
		virtual cg::Vector2d getSize() = 0;
	};
}

#endif