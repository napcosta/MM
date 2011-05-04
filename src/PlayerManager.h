//
//  PlayerManager.h
//  cglib
//
//  Created by Inês on 5/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "cg.h"

namespace Micromachines {
	
	class DirtParticleManager;
	class Car;
	
	class PlayerManager : public cg::Group, public cg::GroupDraw, public cg::GroupUpdate {
	private:
		bool _2Players;
		Car *_secondPlayer;
		DirtParticleManager *_secondPlayerDPM;
		std::vector<Car*> _players;
		std::vector<DirtParticleManager*> _playersDPM;
		typedef std::vector<Car*>::iterator tplayersIterator;
		typedef std::vector<DirtParticleManager*>::iterator tDPMIterator;
		
	public:
		PlayerManager();
		~PlayerManager();
		void createEntities();
		void draw();
		void update(unsigned long elapsed_millis);
		void addOrRemovePlayer2();
		std::vector<Car*> getPlayers();
		Car* firstPlayer();
		Car* secondPlayer();
		bool hasTwoPlayers();
	};
}

#endif