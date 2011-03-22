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

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <string>
#include <vector>
#include "Test.h"

namespace cg {

	/** cg::TestSuite groups cg::Test's together to be run as a batch.
	 *  Look at the cglib.test project for concrete examples of use.
	 */
	class TestSuite {
	protected:
		std::string _name;
		std::vector<Test*> _suite;

	public:
		TestSuite(std::string name) {
			_name = name;
		}
		virtual ~TestSuite() {
		}

		void addTest(Test *test) {
			_suite.push_back(test);
		}
		void run() {
			std::cout << "Running Suite: " << _name;
			std::vector<Test*>::iterator iend = _suite.end();
			for(std::vector<Test*>::iterator i = _suite.begin(); i != iend; i++) {
				std::cout << std::endl << "  ";
				(*i)->do_test();
				delete (*i);
			}
			std::cout << std::endl << std::endl;
			std::cout << "Press <return>.";
			getchar();
		}
	};

}

#endif // TESTSUITE_H
