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
//#include <Math.h>
namespace Micromachines {

	class Controller : public cg::Entity,
			   public cg::IKeyboardEventListener {

	private:
		Car* _player1;
		Car* _player2;
		cg::Vector2d _dirKeysP1, _dirKeysP2;



	public:
		Controller();
		virtual ~Controller();
		void init();
		void onKeyPressed(unsigned char key);
		void onKeyReleased(unsigned char key);
		void onSpecialKeyPressed(int key);
		void onSpecialKeyReleased(int key);
	};

}

#endif /* CONTROLLER_H_ */
