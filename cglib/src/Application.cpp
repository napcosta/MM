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

#include "Application.h"

namespace cg {

    Application::Application() {
		setup();
    }
    Application::Application(const std::string property_file) {
		setup();
		try {
			cg::Properties::instance()->load(property_file);
		} catch(std::runtime_error& e) {
			DebugFile::instance()->writeException(e);
			throw e;
		}
    }
	inline
	void Application::setup() {
        _time.last = 0;
        _time.current = 0;
        _time.elapsed = 0;
        _window.caption = "OpenGL GLUT Application";
        _window.x = 100;
        _window.y = 100;
        _window.width = 640;
        _window.height = 480;
        _window.display_mode = GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH;
		_isFirstUpdate = true;
	}
    Application::~Application() {
    }
    const tWindow& Application::getWindow() const {
        return _window;
    }
    const tTime& Application::getTime() const {
        return _time;
    }
    void Application::onInit() {
        glShadeModel(GL_SMOOTH);
		try {
			createEntities();
		} catch(std::runtime_error& e) {
			DebugFile::instance()->writeException(e);
			throw e;
		}
		Registry::instance()->init();
    }
    inline
    void Application::updateFrameTime() {
        ftime(&_timeb);
		_time.last = _time.current;
		_time.current = (_timeb.time * 1000) + _timeb.millitm;
		_time.elapsed = _time.current - _time.last;
    }
    void Application::onUpdate() {
        updateFrameTime();
		if(_isFirstUpdate) {
			_isFirstUpdate = false;
			return;
		}
		DebugNotifier::instance()->debug();
		UpdateNotifier::instance()->update(_time.elapsed);
    }
	inline
	void Application::setOverlayProjection() {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,_window.width,0,_window.height);  
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	}
    void Application::onDisplay() {
        glClearColor(0.1,0.1,0.1,0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // 1st pass
        glEnable(GL_DEPTH_TEST);
        DrawNotifier::instance()->draw();
        // 2nd pass
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		setOverlayProjection();
        DrawOverlayNotifier::instance()->drawOverlay();
        glDisable(GL_BLEND);
    }
    void Application::onReshape(int w, int h) {
        glViewport(0,0,w,h);
        _window.width = w;
        _window.height = h;
    }
	void Application::addEntity(Entity *entity) {
		if(entity != 0) {
			Registry::instance()->add(entity);
		}
	}
	void Application::shutdown() {
		KeyboardEventNotifier::instance()->cleanup();
		MouseEventNotifier::instance()->cleanup();
		ReshapeEventNotifier::instance()->cleanup();
		UpdateNotifier::instance()->cleanup();
		DrawNotifier::instance()->cleanup();
		DrawOverlayNotifier::instance()->cleanup();
		DebugNotifier::instance()->cleanup();
		Registry::instance()->cleanup();
		DebugFile::instance()->cleanup();
		KeyBuffer::instance()->cleanup();
		Properties::instance()->cleanup();
		Util::instance()->cleanup();
	}
	void Application::dump() const {
		Registry::instance()->dump();
		DebugFile::instance()->writeLine("[Notifiers]");
		UpdateNotifier::instance()->dump();
		DrawNotifier::instance()->dump();
		DrawOverlayNotifier::instance()->dump();
		KeyboardEventNotifier::instance()->dump();
		MouseEventNotifier::instance()->dump();
		ReshapeEventNotifier::instance()->dump();
		DebugNotifier::instance()->dump();
		DebugFile::instance()->newLine();
	}
}
