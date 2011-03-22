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

#ifndef GROUP_DRAW_H
#define GROUP_DRAW_H

#include "Group.h"
#include "IDrawListener.h"

namespace cg {

	/** cg::GroupDraw is a Group that automatically invokes the draw method
	 *  of all its inner entities. The preDraw method is called before
	 *  invoking the children methods, while the postDraw is called after.
	 */
	class GroupDraw : public IGetEntities, public IDrawListener {
	protected:
		virtual void preDraw() {}
		virtual void postDraw() {}
    public:
		IGETENTITIES_IMPLEMENTATION
		virtual void draw() {
			preDraw();
			FOR_EACH_ENTITY(draw(),IDrawListener)
			postDraw();
		}
    };

}

#endif // GROUP_DRAW_H
