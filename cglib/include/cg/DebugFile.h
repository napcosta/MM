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

#ifndef DEBUG_FILE_H
#define DEBUG_FILE_H

#include <fstream>
#include <string>
#include <stdexcept>

namespace cg {

	/** cg::DebugFile is singleton class that writes to a single text 
	 *  file for debug purposes. Any class can write to this file using
	 *  the methods cg::DebugFile::write, cg::DebugFile::writeLine and
	 *  cg::DebugFile::newLine. Alternatively, any class can get the 
	 *  direct output file stream handle through the method 
	 *  cg::DebugFile::getOutputFileStream.
	 */
	class DebugFile  {

	private: 
		static DebugFile* _instance; 
		DebugFile();
		std::ofstream _file;

	public: 
		static DebugFile* instance(); 
		virtual ~DebugFile();
		void cleanup();
		std::ofstream& getOutputFileStream();
		void write(const std::string& s);
		void writeLine(const std::string& s);
		void newLine();
		void writeException(std::runtime_error& e);
	};
}

#endif // DEBUG_FILE_H