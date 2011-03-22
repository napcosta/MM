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

#ifndef REGISTRY_H
#define REGISTRY_H

#include <fstream>
#include <map>
#include "DebugFile.h"
#include "DebugNotifier.h"
#include "DrawNotifier.h"
#include "DrawOverlayNotifier.h"
#include "Entity.h"
#include "GroupDebug.h"
#include "GroupDraw.h"
#include "GroupDrawOverlay.h"
#include "GroupKeyboardEvent.h"
#include "GroupMouseEvent.h"
#include "GroupReshapeEvent.h"
#include "GroupUpdate.h"
#include "IDebugListener.h"
#include "IDrawListener.h"
#include "IDrawOverlayListener.h"
#include "IKeyboardEventListener.h"
#include "IMouseEventListener.h"
#include "IReshapeEventListener.h"
#include "IUpdateListener.h"
#include "KeyboardEventNotifier.h"
#include "MouseEventNotifier.h"
#include "ReshapeEventNotifier.h"
#include "UpdateNotifier.h"

namespace cg {

	/** cg::Registry is a singleton notifier that maintains a list
	 *  of all cg::Entity of the application. When the cg::Registry::init 
	 *  method is invoked, all the entities are called through
	 *  the cg::Entity::init method, independently of being enabled or not.
	 */

	class Registry {

	private:
		static Registry* _instance; 
		Registry();

		std::map<const std::string, Entity*> _entities;
		typedef std::map<const std::string, Entity*>::iterator tEntityIterator;

		void connectEntity(Entity* entity);
		void disconnectEntity(Entity* entity);
		void dumpEntity(Entity* entity, std::ofstream& file);
		void shutdown();

	public:
		static Registry* instance(); 
		virtual ~Registry();
		void cleanup();

		void init();
		unsigned int size() const;
		bool exists(const std::string& id);
		Entity* get(const std::string& id);
		void add(Entity* entity);
		void remove(const std::string& id);
		void removeAll();
		void destroy(const std::string& id);
		void destroyAll();
		void dump();
	};
}

#endif // REGISTRY_H