#pragma once

#include "Event.h"

class GAC : public Stringable
{

	std::vector <Event> _events;

public:

	GAC();

	std::string toString() const;
	std::string toXML() const;
	std::string toJSON() const;
	std::string toCSV() const;

};