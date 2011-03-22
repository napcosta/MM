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

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <fstream>
#include "State.h"

namespace cg {

	/** cg::Entity is the base class of all simulation objects.
	 *  A cg::Entity has a string identifier and can be turned on or off.
	 *  When turned off, all callbacks will be disabled. 
	 *  All initialization of the object should be performed in the init() 
	 *  method: only by then, OpenGL commands are ready to be used.
	 */
	class Entity {

	protected:
		std::string _id;

	public:
		State state;

		Entity(const std::string& id) : _id(id) {}
		virtual ~Entity() {}

		const std::string& getId() const { return _id; }
		virtual void init() = 0;

		virtual void dump(std::ofstream& file) {
			file << state << " " << _id;
		}
	};
}

#endif // ENTITY_H
