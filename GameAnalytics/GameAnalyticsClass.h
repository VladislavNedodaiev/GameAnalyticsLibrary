#pragma once

#include "Event.h"

#include <fstream>

class GAC : public Stringable, public Serializable
{

	bool _tofile(const std::string filename, const std::string data) const;

public:

	std::vector <Event> events;

	std::string toString() const;
	std::string toXML() const;
	std::string toJSON() const;
	std::string toCSV() const;

	std::string toXML(const std::string filename) const;
	std::string toJSON(const std::string filename) const;
	std::string toCSV(const std::string filename) const;

};