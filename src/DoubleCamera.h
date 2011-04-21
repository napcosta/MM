/*
 * NearCamera.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef DOUBLECAMERA_H_
#define DOUBLECAMERA_H_

#include "cg.h"
#include "Car.h"
#define PI 3.14159265

namespace Micromachines {

	class DoubleCamera : public cg::Entity, public cg::IDrawListener {
	
	private:
		double _winWidth, _winHeight;
		double _rotation;
		cg::Vector3d _position;
		Car* _car;

	public:
		DoubleCamera();
		virtual ~DoubleCamera();
		void init();
		void draw();
	};

}

#endif /* NearCamera_H_ */
