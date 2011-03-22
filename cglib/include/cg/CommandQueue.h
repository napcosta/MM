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

#ifndef COMMAND_QUEUE_H
#define COMMAND_QUEUE_H

#include <string>
#include <queue>
#include <stdexcept>
#include "Notifier.h"

namespace cg {

	//---<CommandQueue>---

	template <class E>
	class Notifier;

	template <class E>
	struct ListenerInfo;

	template <class E>
	class Command {
	public:
		Command() {}
		virtual ~Command() {}
		virtual void execute(Notifier<E>* notifier) = 0;
	};

	/** CommandQueue maintains a queue of the commands issued on the locked 
	 *  notifier that will be executed (by the same order) when it unlocks.
	 */
	template <class E>
	class CommandQueue {
	private:
		std::queue<Command<E>*> _commands;
		std::map<const std::string,ListenerInfo<E>*> _newElements;
        typedef typename std::map<const std::string,ListenerInfo<E>*>::iterator newElementItr;

	public:
		CommandQueue() {}
		~CommandQueue() {}
		void add(Command<E>* command);
		void addListenerInfo(ListenerInfo<E> *info);
		bool existsListenerInfo(const std::string& id);
		ListenerInfo<E>* getListenerInfo(const std::string& id);
		void execute(Notifier<E>* notifier);
		void destroy();
	};
	template <class E>
	void CommandQueue<E>::add(Command<E>* command) {
		_commands.push(command);
	}
	template <class E>
	void CommandQueue<E>::addListenerInfo(ListenerInfo<E> *info) {
		std::string id = info->entity->getId();
		std::pair<newElementItr,bool> result = _newElements.insert( std::make_pair(id,info) );
		if(result.second == false) {
			throw std::invalid_argument("[cg::CommandQueue] listener '" + id + "' already exists.");
		}
	}
	template <class E>
	bool CommandQueue<E>::existsListenerInfo(const std::string& id) {
		return (_newElements.count(id) != 0);
	}
	template <class E>
	ListenerInfo<E>* CommandQueue<E>::getListenerInfo(const std::string& id) {
		newElementItr i = _newElements.find(id);
		if(i == _newElements.end()) {
			return 0;
		}
		return i->second;
	}
	template <class E>
	void CommandQueue<E>::execute(Notifier<E>* notifier) {
		while(_commands.empty() == false) {
			Command<E>* c = _commands.front();
			c->execute(notifier);
			_commands.pop();
			delete c;
		}
		_newElements.clear();
	}
	template <class E>
	void CommandQueue<E>::destroy() {
		while(_commands.empty() == false) {
			Command<E>* c = _commands.front();
			_commands.pop();
			delete c;
		}
		_newElements.clear();
	}

	//---<Commands>---

	template <class E>
	class AddCommand : public Command<E> {
	private:
		ListenerInfo<E>* _info;
	public:
		AddCommand(ListenerInfo<E>* info) {
			_info = info;
		}
		~AddCommand() {
		}
		void execute(Notifier<E>* notifier) {
			notifier->addInfo(_info);
		}
	};

	template <class E>
	class RemoveCommand : public Command<E> {
	private:
		std::string _id;
	public:
		RemoveCommand(std::string id) {
			_id = id;
		}
		~RemoveCommand() {
		}
		void execute(Notifier<E>* notifier) {
			notifier->remove(_id);
		}
	};

	template <class E>
	class RemoveAllCommand : public Command<E> {
	public:
		RemoveAllCommand() {
		}
		~RemoveAllCommand() {
		}
		void execute(Notifier<E>* notifier) {
			notifier->removeAll();
		}
	};

	template <class E>
	class DestroyCommand : public Command<E> {
	private:
		std::string _id;
	public:
		DestroyCommand(std::string id) {
			_id = id;
		}
		~DestroyCommand() {
		}
		void execute(Notifier<E>* notifier) {
			notifier->destroy(_id);
		}
	};

	template <class E>
	class DestroyAllCommand : public Command<E> {
	public:
		DestroyAllCommand() {
		}
		~DestroyAllCommand() {
		}
		void execute(Notifier<E>* notifier) {
			notifier->destroyAll();
		}
	};
}

#endif