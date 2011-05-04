//
//  PlayerManager.cpp
//  cglib
//
//  Created by Inês on 5/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "PlayerManager.h"

namespace Micromachines {
	
	PlayerManager::PlayerManager() : cg::Group("PlayerManager")
	{
		_2Players = false;
	}
	
	PlayerManager::~PlayerManager()
	{}
	
	void PlayerManager::createEntities()
	{
		Car *car = new Car("Car", 1);
		car->init();
		_players.push_back(car);
		DirtParticleManager *dpm = new DirtParticleManager("DPM1", car);
		dpm->init();
		_playersDPM.push_back(dpm);
		
		_secondPlayer = new Car("Car2", 2);
		_secondPlayer->init();
		_secondPlayerDPM = new DirtParticleManager("DPM1", _secondPlayer);
		_secondPlayerDPM->init();
	}
	
	void PlayerManager::draw()
	{
		for(tplayersIterator i = _players.begin(); i != _players.end(); i++){
			(*i)->draw();
		}
		
		for(tDPMIterator i = _playersDPM.begin(); i != _playersDPM.end(); i++){
			(*i)->draw();
		}
		
	}
	
	void PlayerManager::update(unsigned long elapsed_millis)
	{
		for(tplayersIterator i = _players.begin(); i != _players.end(); i++){
			(*i)->update(elapsed_millis);
		}
		
		for(tDPMIterator i = _playersDPM.begin(); i != _playersDPM.end(); i++){
			(*i)->update(elapsed_millis);
		}
		
	}
	
	void PlayerManager::addOrRemovePlayer2()
	{
		if (_2Players) {
			_players.pop_back();
			_playersDPM.pop_back();
			_2Players = false;
		} else {
			_secondPlayer->positionSecondPlayer(firstPlayer()->getPosition(), firstPlayer()->getRotation());
			_players.push_back(_secondPlayer);
			_playersDPM.push_back(_secondPlayerDPM);
			_2Players = true;
		}
		
	}
	
	std::vector<Car*> PlayerManager::getPlayers()
	{
		return _players;
	}
	
	Car* PlayerManager::firstPlayer()
	{
		if(_players.empty()){
			return NULL;
		}
		return _players[0];
	}
	
	Car* PlayerManager::secondPlayer()
	{
		if(_2Players){
			return _players[1];
		} else return NULL;
	}
}