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

#ifndef GROUP_H
#define GROUP_H

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Entity.h"

#define FOR_EACH_ENTITY(COMMAND,INTERFACE)\
	std::vector<Entity*>* entities = getEntities();\
	std::vector<Entity*>::iterator iend = end();\
	for (std::vector<Entity*>::iterator i = begin(); i != iend; i++) {\
		if((*i)->state.isEnabled()) {\
			INTERFACE* obj = dynamic_cast<INTERFACE*>(*i);\
			obj->COMMAND; }}

#define IGETENTITIES_IMPLEMENTATION\
	virtual std::vector<Entity*>* getEntities() {\
		Group* group = (Group*)dynamic_cast<Group*>(this);\
		return group->getEntities(); }\
	virtual std::vector<Entity*>::iterator begin() {\
		Group* group = (Group*)dynamic_cast<Group*>(this);\
		return group->begin(); }\
	virtual std::vector<Entity*>::iterator end() {\
		Group* group = (Group*)dynamic_cast<Group*>(this);\
		return group->end(); }

namespace cg {

	class IGetEntities {
    public:
        virtual std::vector<Entity*>* getEntities() = 0;
		virtual std::vector<Entity*>::iterator begin() = 0;
		virtual std::vector<Entity*>::iterator end() = 0;
    };

	/** cg::Group is an entity that contains other entities.
	 *  Group can implement the same interfaces as any entity plus the
	 *  specific group classes that automatically distribute events
	 *  to the inner entities.
	 *  Note that all methods dealing with the contained entites are
	 *  protected, and can only be called from inside the subclass.
	 */
	class Group : public Entity, public IGetEntities {
	private:
		void shutdown();

	protected:
		std::map<std::string,Entity*> _names;
		typedef std::map<std::string,Entity*>::iterator tNameIterator;

		std::vector<Entity*> _entities;
		typedef std::vector<Entity*>::iterator tEntityIterator;

		unsigned int size();
		bool exists(const std::string& id);
		Entity *get(const std::string& id);
		void add(Entity* entity);
		void remove(const std::string& id);
		void removeAll();
		void destroy(const std::string& id);
		void destroyAll();

		virtual void createEntities() = 0;
		virtual void preInit() {}
		virtual void postInit() {}

	public:
		Group(const std::string& id);
		virtual ~Group();
		void init();
		virtual void dump(std::ofstream& file);
		// IGetEntities
		std::vector<Entity*>* getEntities();
		std::vector<Entity*>::iterator begin();
		std::vector<Entity*>::iterator end();
	};
}

#endif // GROUP_H
