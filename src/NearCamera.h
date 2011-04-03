/*
 * NearCamera.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef NEARCAMERA_H_
#define NEARCAMERA_H_
#include "cg.h"
#include "Car.h"
#define PI 3.14159265

namespace Micromachines {

	class NearCamera : public cg::Entity, public cg::IDrawListener {

	private:
		double _winWidth, _winHeight;
		double _carRotation;
		cg::Vector2d _position;
		Car* _car;

	public:
		NearCamera();
		virtual ~NearCamera();
		void init();
		void draw();
	};

}

#endif /* NearCamera_H_ */
