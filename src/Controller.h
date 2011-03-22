/*
 * Controller.h
 *
 *  Created on: Aug 2, 2010
 *      Author: pinto
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Hero.h"

#include "cg/cg.h"

namespace Armageddon {

	class Controller : public cg::Entity,
			   public cg::IKeyboardEventListener {

	private:
		Hero* _hero;
		cg::Vector2d _dirKeys;



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
