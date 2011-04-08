/*
 * PhysicalEntity.h
 *
 *  Created on: Aug 3, 2010
 *      Author: pinto
 */

#ifndef PHYSICALENTITY_H_
#define PHYSICALENTITY_H_

#include "cg.h"

namespace Micromachines {

	class PhysicalEntity : public cg::IUpdateListener,
          		     public cg::IReshapeEventListener{
	
	public:
		PhysicalEntity();
		virtual ~PhysicalEntity();
		void update(unsigned long elapsed_millis);
	};

	}

#endif /* PHYSICALENTITY_H_ */
