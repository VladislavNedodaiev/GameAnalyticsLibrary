#pragma once

#include "Event.h"

class GAC : public Stringable, public Serializable
{

public:

	std::vector <Event> events;

	std::string toString() const;
	std::string toXML() const;
	std::string toJSON() const;
	std::string toCSV() const;

};