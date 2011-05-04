/*
 * DirtParticle.h
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#ifndef DirtParticle_H_
#define DirtParticle_H_

#include "cg.h"
#include "Particle.h"

namespace Micromachines {
	
	class Car;
	class TrackManager;

	class DirtParticle : public Particle
	{

	private:
		cg::Vector3d _position, _size;
		cg::Vector3d _color;
		cg::Vector3d _velocity, _acceleration;
		double _winWidth, _winHeight;
		bool _carOfTrack;
		Car* _car;
		TrackManager* _trackManager;

	//	double randomBetween(double min, double max);

	public:
		DirtParticle(std::string id, cg::Vector3d color, cg::Vector3d velocity, Car* car);
		~DirtParticle();
		void init();
		void reset(cg::Vector3d position);
		void update(unsigned long elapsed_millis);
	};

}

#endif /* DirtParticle_H_ */
