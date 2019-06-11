#pragma once

#include "HTTPRequest.hpp"
#include "Event.h"

#include <fstream>
#include <http.h>
#include <sstream>
#include <iostream>

class GAC : public Stringable, public Serializable
{

	bool _tofile(const std::string filename, const std::string data) const;
	bool _toserver(const std::string webaddress, const std::string data, const std::string extension) const;

public:

	enum PostMethod {
	
		FileSystem = 0,
		Server = 1
	
	};

	std::vector <Event> events;

	std::string toString() const;

	std::string toXML() const;
	std::string toJSON() const;
	std::string toCSV() const;

	std::string toXML(const std::string path, PostMethod method) const;
	std::string toJSON(const std::string path, PostMethod method) const;
	std::string toCSV(const std::string path, PostMethod method) const;

};