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

#ifndef GROUP_MOUSE_EVENT_H
#define GROUP_MOUSE_EVENT_H

#include "Group.h"
#include "IMouseEventListener.h"

namespace cg {

	/** cg::GroupMouseEvent is a Group that automatically broadcasts
	 *  mouse events to its inner entities. The 'pre' methods are 
	 *  called before sending the event to the inner entities, while 
	 *  the 'post' methods are called after.
	 */
	class GroupMouseEvent : public IGetEntities, public IMouseEventListener {
	protected:
		virtual void preOnMouse(int button, int state, int x, int y) {}
		virtual void postOnMouse(int button, int state, int x, int y) {}
		virtual void preOnMouseMotion(int x, int y) {}
		virtual void postOnMouseMotion(int x, int y) {}
		virtual void preOnMousePassiveMotion(int x, int y) {}
		virtual void postOnMousePassiveMotion(int x, int y) {}
    public:
		IGETENTITIES_IMPLEMENTATION
		void onMouse(int button, int state, int x, int y) {
			preOnMouse(button,state,x,y);
			FOR_EACH_ENTITY(onMouse(button,state,x,y),IMouseEventListener)
			postOnMouse(button,state,x,y);
		}
		void onMouseMotion(int x, int y) {
			preOnMouseMotion(x,y);
			FOR_EACH_ENTITY(onMouseMotion(x,y),IMouseEventListener)
			postOnMouseMotion(x,y);
		}
		void onMousePassiveMotion(int x, int y) {
			preOnMousePassiveMotion(x,y);
			FOR_EACH_ENTITY(onMousePassiveMotion(x,y),IMouseEventListener)
			postOnMousePassiveMotion(x,y);
		}
    };

}

#endif // GROUP_MOUSE_EVENT_H
