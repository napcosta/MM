/*
 * BEVCamera.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef BEVCAMERA_H_
#define BEVCAMERA_H_
#include "cg.h"
#include "Car.h"
#define PI 3.14159265

namespace Micromachines {

	class BEVCamera : public cg::Entity, public cg::IDrawListener {

	private:
		double _winWidth, _winHeight;
		double _carRotation;
		cg::Vector2d _position;
		Car* _car;

	public:
		BEVCamera();
		virtual ~BEVCamera();
		void init();
		void draw();
	};

}

#endif /* BEVCAMERA_H_ */
