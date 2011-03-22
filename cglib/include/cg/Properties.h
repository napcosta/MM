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

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "Singleton.h"
#include "Vector.h"

namespace cg {

	/** cg::Properties is a singleton that maintains pairs (name, value) imported from 
	 *  a text file. 
	 *  The file format is as follows. Each property is written on a different line.
	 *  The format is [name] = [value], where name does not contain any white character.
	 *  The value field is read from the separator '=' to the end of line, and as such
	 *  can contain white characters.
	 *  Only a set of values are supported for direct type convertion. 
	 *  For other types, use the cg::Properties::getString method to obtain the value as 
	 *  a string and parse it.
	 *  Lines which first non-blank character is a '#' are comments.
	 */
	class Properties {

	SINGLETON_HEADER(Properties)

	private:
		static const char COMMENT;
		std::map<const std::string,const std::string> _properties;
		typedef std::map<const std::string,const std::string>::iterator tPropertyIterator;
		void parseLine(const std::string& line);

	public:
		void load(const std::string& filename);
		bool exists(const std::string& name);

		int getInt(const std::string& name);
		float getFloat(const std::string& name);
		double getDouble(const std::string& name);
		std::string getString(const std::string& name);
		
		Vector2d getVector2d(const std::string& name);
		Vector2i getVector2i(const std::string& name);
		Vector3d getVector3d(const std::string& name);
		Vector3i getVector3i(const std::string& name);
	};
}

#endif // PROPERTIES_H