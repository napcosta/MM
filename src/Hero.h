/*
 * Hero.h
 *
 *  Created on: Jul 25, 2010
 *      Author: pinto
 */

#ifndef HERO_H_
#define HERO_H_

#include <string>
#include <ctime>
#include <math.h>
#include "cg.h"

namespace Armageddon {

	class Hero : public cg::Entity,
		     public cg::IDrawListener,
		     public cg::IMouseEventListener,
		     public cg::IUpdateListener {

	private:
		double _winHeight;
		cg::Vector2d _position;
		cg::Vector2d _velocity;
		cg::Vector2d _size;
		cg::Vector2d _appForce;
		cg::Vector2d _acceleration;
		double _atrittionFactor;
		double _mass;
		double _maxSpeed;
		double _movForce;
		cg::Vector2d _arrowKeyPressed;

	public:
		Hero(std::string id);
		~Hero();
		void init();
		void draw();
		void onMouse(int button, int state, int x, int y);
		void onMouseMotion(int x, int y);
		void onMousePassiveMotion(int x, int y);
		void update(unsigned long elapsed_millis);
		void applyForce(cg::Vector2d force);
		void setArrowKeyPressed(cg::Vector2d val);
		void keyBreak(int direction);
		cg::Vector2d getArrowKeyPressed();
	};

}

#endif /* HERO_H_ */
