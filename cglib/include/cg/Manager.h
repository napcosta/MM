// This file is part of CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2007 Carlos Martinho
// Updated 2010 by J M Brisson Lopes (Mac OS X support)


#ifndef MANAGER_H
#define MANAGER_H

#include "Application.h"
#include "KeyboardEventNotifier.h"
#include "KeyBuffer.h"
#include "MouseEventNotifier.h"
#include "ReshapeEventNotifier.h"
#include "Singleton.h"

namespace cg {

	/** cg::Manager is a singleton class that connects a cg::Application to 
	 *  the OpenGL and GLUT callbacks.
	 *  To run a cg::Application, use the runApp method. From that momment on,
	 *  all control of the application is based on callbacks.
	 *  Keyboard events are dispatched to cg::KeyboardEventNotifier and cg::Keybuffer.
	 *  Mouse events are dispatched to cg::MouseEventNotifier.
	 *  Reshape events are dispatched to cg::ReshapeEventNotifier.
	 *  cg::Application::update is called at the frame rate.
	 *  cg::Application::display is called after each update.
	 */
    class Manager {

	SINGLETON_HEADER(Manager)

    private:
        Application* _app;
        int _intervalMillis;

    public:
        Application* getApp();
	    void runApp(Application *app, int fps, int glut_argc, char** glut_argv);
		void shutdownApp();
        int getIntervalMillis() const;
    };

}

#endif // MANAGER_H
