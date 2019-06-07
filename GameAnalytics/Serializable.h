#pragma once

#include <string>

struct Serializable abstract
{

	virtual std::string toXML() const;
	virtual std::string toJSON() const;
	virtual std::string toCSV() const;

};