/*
 * NearCamera.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef DOUBLECAMERA_H_
#define DOUBLECAMERA_H_

#include "cg.h"

#define PI 3.14159265

namespace Micromachines {
	
	class PlayerManager;
	class Car;

	class DoubleCamera : public cg::Entity, public cg::IDrawListener {
	
	private:
		double _winWidth, _winHeight;
		PlayerManager* _pm;
		Car* _player1;
		Car* _player2;

	public:
		DoubleCamera();
		virtual ~DoubleCamera();
		void init();
		void draw();
	};

}

#endif /* NearCamera_H_ */
