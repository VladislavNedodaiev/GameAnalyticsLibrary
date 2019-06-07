#include "GameAnalyticsClass.h"

std::string GAC::toString() const
{

	int i = 0;
	int count = this->events.size();

	if (count <= 0)
		return "";

	std::string result = "";

	while (i < count - 1)
	{
		result += this->events[i].toString() + "\n";
		i++;
	}

	result += this->events[i].toString();

	return result;

}

std::string GAC::toXML() const
{

	std::string result = "";

	result += "<ArrayOfEvent xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">";

	int count = this->events.size();
	for (int i = 0; i < count; i++)
	{

		result += this->events[i].toXML();

	}

	result += "</ArrayOfEvent>";

	return result;

}

std::string GAC::toJSON() const
{

	std::string result = "";

	return result;

}

std::string GAC::toCSV() const
{

	std::string result = "";

	return result;

}