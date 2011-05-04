/*
 * Controller.h
 *
 *  Created on: Aug 2, 2010
 *      Author: pinto
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "cg.h"
#include "Car.h"
#include "PlayerManager.h"

//#include <Math.h>
namespace Micromachines {

	class Controller : public cg::Entity,
			   public cg::IKeyboardEventListener {

	private:
		PlayerManager* _pm;
		cg::Vector2d _dirKeysP1, _dirKeysP2;
		bool _2Players;
		Car* _firstPlayer;
		Car* _secondPlayer;
				   
		void specialKeyPressed(int key);
				   void specialKeyReleased(int key);
				   void keyPressed(int key);
				   void keyReleased(int key);


	public:
		Controller();
		virtual ~Controller();
		void init();
		void onKeyPressed(unsigned char key);
		void onKeyReleased(unsigned char key);
		void onSpecialKeyPressed(int key);
		void onSpecialKeyReleased(int key);
		void setPlayers(std::vector<Car*> players);
	};

}

#endif /* CONTROLLER_H_ */
