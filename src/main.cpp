/*
 * main.cpp
 *
 *  Created on: Jul 20, 2010
 *      Author: pinto
 */

#include "App.h"
#include "cg/cg.h"
int main(int argc, char** argv) {

	cg::Manager::instance()->runApp(new Armageddon::App(), 60, argc,argv);
	return 0;

}
