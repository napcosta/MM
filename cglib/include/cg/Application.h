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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <sys/timeb.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "DebugFile.h"
#include "DebugNotifier.h"
#include "DrawNotifier.h"
#include "DrawOverlayNotifier.h"
#include "Entity.h"
#include "KeyBuffer.h"
#include "KeyboardEventNotifier.h"
#include "MouseEventNotifier.h"
#include "Properties.h"
#include "Registry.h"
#include "ReshapeEventNotifier.h"
#include "UpdateNotifier.h"
#include "Util.h"

namespace cg {

    typedef struct {
        std::string caption;
        unsigned int x, y, width, height;
        int display_mode;
    } tWindow;

    typedef struct {
        unsigned long last, current, elapsed;
    } tTime;

	/** cg::Application is an abstract class controlling the initialization, 
	 *  update and display cycle of the application.
	 *  To create an application, just create a subclass of cg::Application and 
	 *  implement the method cg::Application::createEntities using the protected
     *  method cg::Application::addEntity to add each entity, one by one.
	 *  This method will automatically register the cg::Entity in the correct 
	 *  notifiers, according to its implemented interfaces. These in turn will
	 *  be called by each notifier during the simulation cycle.
	 *  The simulation cycle can be resumed to the following ordered steps: 
	 *  debug, update, draw and drawOverlay. The init step is performed once at 
	 *  the beginning of the simulation.
	 *  For a detailed view of the simulation cycle, please refer to the methods
	 *  the cg::Application::init, cg::Application::update, and 
	 *  cg::Application::display.
	 *  These methods can be redefined in the subclass if a finer control of
	 *  the simulation cycle is needed.
	 */
    class Application {

    protected:
        tWindow _window;

        tTime _time;
        struct timeb _timeb;
        void updateFrameTime();

		bool _isFirstUpdate;
		void setup();
		void addEntity(Entity* entity);
		void onShutdown();
		virtual void setOverlayProjection();

    public:
		Application();
		Application(const std::string property_file);
        virtual ~Application();

        const tWindow& getWindow() const;
        const tTime& getTime() const;

        virtual void onInit();
        virtual void onUpdate();
        virtual void onDisplay();
        void onReshape(int w, int h);
		void shutdown();

        virtual void createEntities() = 0;
		void dump() const;
    };

}

#endif // APPLICATION_H
