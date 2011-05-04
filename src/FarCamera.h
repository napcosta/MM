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
#include "PlayerManager.h"

#define PI 3.14159265

namespace Micromachines {

	class FarCamera : public cg::Entity, public cg::IDrawListener {

	private:
		double _winWidth, _winHeight;
		double _carRotation;
		cg::Vector3d _position;
		PlayerManager* _pm;
		Car* _car;

	public:
		FarCamera();
		virtual ~FarCamera();
		void init();
		void draw();
	};

}

#endif /* BEVCAMERA_H_ */
