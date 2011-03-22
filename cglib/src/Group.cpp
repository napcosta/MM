// Updated 2010 by J M Brisson Lopes (Mac OS X support)

#include "Group.h"
#include <stdexcept>


namespace cg {

	Group::Group(const std::string& id) : Entity(id) {
	}
	Group::~Group() { 
		shutdown(); 
	}
	unsigned int Group::size() {
		return (unsigned int)_entities.size();
	}
	bool Group::exists(const std::string& id) {
		return (_names.count(id) != 0);
	}
	Entity* Group::get(const std::string& id) {
		tNameIterator i = _names.find(id);
		if(i != _names.end()) {
			return i->second;
		}
		return 0;
	}
	void Group::add(Entity* entity) {
		std::string id = entity->getId();
		std::pair<tNameIterator,bool> result = _names.insert(std::make_pair(id, entity));
		if(result.second == false) {
			throw std::runtime_error("[cg::Group] entity '" + id + "' already exists.");
		} else {
			_entities.push_back(entity);
		}
	}
	void Group::remove(const std::string& id) {
		tNameIterator i = _names.find(id);
		if(i != _names.end()) {
			tEntityIterator j = find(_entities.begin(),_entities.end(),i->second);
			_entities.erase(j);
			_names.erase(id);
		}
	}
	void Group::removeAll() {
		_names.clear();
		_entities.clear();
	}
	void Group::destroy(const std::string& id) {
		tNameIterator i = _names.find(id);
		if(i != _names.end()) {
			tEntityIterator j = find(_entities.begin(),_entities.end(),i->second);
			delete (*j);
			_entities.erase(j);
			_names.erase(id);
		}
	}
	void Group::destroyAll() {
		for(tEntityIterator i = _entities.begin(); i != _entities.end(); i++) {
			delete (*i);
		}
		_names.clear();
		_entities.clear();
	}
	void Group::init() {
		preInit();
		createEntities();
		for(tEntityIterator i = _entities.begin(); i != _entities.end(); i++) {
			(*i)->init();
		}
		postInit();
	}
	void Group::dump(std::ofstream& file) {
		file << state << " " << _id << " [Group of " << size() << "]";
		for(tEntityIterator i = _entities.begin(); i != _entities.end(); i++) {
			file << std::endl;
			file << "    ";
			(*i)->dump(file);
		}
	}
	void Group::shutdown() {
		destroyAll();
	}
	std::vector<Entity*>* Group::getEntities() {
		return &_entities; 
	}
	std::vector<Entity*>::iterator Group::begin() { 
		return _entities.begin(); 
	}
	std::vector<Entity*>::iterator Group::end() { 
		return _entities.end(); 
	}
}