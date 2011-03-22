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

#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include "CommandQueue.h"
#include "DebugFile.h"
#include "Entity.h"
#include "State.h"

#define FOR_EACH_LISTENER(COMMAND)\
	try {\
		lock();\
		if(state.isEnabled()) {\
			for (tListenerIterator i = _listeners.begin(); i != _listeners.end(); i++) {\
				if((*i)->entity->state.isEnabled()) {\
					(*i)->listener->COMMAND;\
				}\
			}\
		}\
		unlock();\
	} catch(std::runtime_error& e) {\
		cg::DebugFile::instance()->writeException(e);\
		throw e;\
	}

#define DUMP_METHOD(CLASS)\
	void dump() {\
		std::ofstream& file = DebugFile::instance()->getOutputFileStream();\
		file << CLASS::instance()->state << " " << #CLASS << " (" << size() << ")" << std::endl;\
		for (tListenerIterator i = _listeners.begin(); i != _listeners.end(); i++) {\
			file << "    " << (*i)->entity->state << " " << (*i)->entity->getId() << std::endl;\
		}\
	}

namespace cg {

	/** cg::ListenerInfo<E> maintains information on a listener implementing interface E.
	 */
	template<class E>
	struct ListenerInfo {
	public:
		E* listener;
		Entity* entity;
		ListenerInfo(E* _listener, Entity* _entity) {
			listener = _listener;
			entity = _entity;
		}
		~ListenerInfo() {
		}
	};

	/** cg::Notifier<E> is an asbtract class maintaining a set of cg::Entity objects
	 *  implementing the callback interface <E>.
	 *  cg::Notifier<E> can be enabled/disabled.
	 *  Note: although cg::Notifier<E> allows for dynamic addition/removal of
	 *  listeners, adding/removing a listener while the callbacks are being
	 *  processed will put this command on a queue, that will only be executed
	 *  at the end of the callback iteration over all listeners.
	 *  It is usually a better design to create a 'manager' class that deals with 
	 *  the dynamic addition/removal of related entities. This manager class can be 
	 *  registered instead of its inner classes, and be an entry point for them.
	 */
	template <class E>
	class Notifier {
	private:
		void shutdown();

	protected:
		std::map<const std::string,ListenerInfo<E>*> _names;
		typedef typename std::map<const std::string,ListenerInfo<E>*>::iterator tNameIterator;

		std::vector<ListenerInfo<E>*> _listeners;
		typedef typename std::vector<ListenerInfo<E>*>::iterator tListenerIterator;

		bool _isLocked;
		CommandQueue<E> _commandQueue;

		Notifier() { _isLocked = false; }
		virtual ~Notifier() { shutdown(); }

	public:
		State state;

		unsigned int size() const;
		bool exists(const std::string& id);
		E* get(const std::string& id);
		void addInfo(ListenerInfo<E>* info);
		void add(E* listener);
		void remove(const std::string& id);
		void removeAll();

		void lock();
		void unlock();
	};

    template<class E>
    unsigned int Notifier<E>::size() const{
		return (unsigned int)_names.size();
    }
    template<class E>
    bool Notifier<E>::exists(const std::string& id) {
		if(_names.count(id) == 0) {
			return _commandQueue.existsListenerInfo(id);
		} else {
			return true;
		}
    }
	template <class E>
	E* Notifier<E>::get(const std::string& id) {
		tNameIterator i = _names.find(id);
		if(i == _names.end()) {
			ListenerInfo<E>* info = _commandQueue.getListenerInfo(id);
			if(info) {
				return info->listener;
			} else {
				return 0;
			}
		} else {
			return i->second->listener;
		}
	}
	template <class E>
	void Notifier<E>::addInfo(ListenerInfo<E>* info) {
		std::string id = info->entity->getId();
		std::pair<tNameIterator,bool> result = _names.insert(std::make_pair(id, info));
		if(result.second == false) {
			delete info;
			throw std::runtime_error("[cg::Notifier] listener '" + id + "' already exists.");
		}
		_listeners.push_back(info);
	}
	template <class E>
	void Notifier<E>::add(E* listener) {
		Entity* entity = dynamic_cast<Entity*>(listener);
		if(entity == 0) {
			throw std::runtime_error("[cg::Notifier] listener is not subclass of cg::Entity.");
		} else {
			std::string id = entity->getId();
			ListenerInfo<E>* info = new ListenerInfo<E>(listener, entity);
			if(_isLocked) {
				_commandQueue.add(new AddCommand<E>(info));
				_commandQueue.addListenerInfo(info);
			} else {
				addInfo(info);
			}
		}
	}
	template <class E>
	void Notifier<E>::remove(const std::string& id) {
		if(_isLocked) {
			_commandQueue.add(new RemoveCommand<E>(id));
		} else {
			tNameIterator i = _names.find(id);
			if(i != _names.end()) {
				tListenerIterator j = find(_listeners.begin(), _listeners.end(), i->second);
				delete (*j);
				_listeners.erase(j);
				_names.erase(id);
			}
		}
	}
	template <class E>
	void Notifier<E>::removeAll() {
		if(_isLocked) {
			_commandQueue.add(new RemoveAllCommand<E>());
		} else {
			for (tListenerIterator i = _listeners.begin(); i != _listeners.end(); i++) {
				delete (*i);
			}
			_listeners.clear();
			_names.clear();
		}
	}
	template <class E>
	void Notifier<E>::lock() {
		_isLocked = true;
	}
	template <class E>
	void Notifier<E>::unlock() {
		_isLocked = false;
		_commandQueue.execute(this);
	}
	template <class E>
	void Notifier<E>::shutdown() {
		for (tListenerIterator i = _listeners.begin(); i != _listeners.end(); i++) {
			delete (*i);
		}
		_listeners.clear();
		_names.clear();
	}
}

#endif // NOTIFIER_H