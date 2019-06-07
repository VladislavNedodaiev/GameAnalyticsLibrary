#define _CRT_SECURE_NO_WARNINGS
#include "Event.h"

void Event::_createTimestamp()
{

	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", timeinfo);

	this->_parametres.push_back(KeyValue("Timestamp", std::string(buffer)));

}

Event::Event()
{

	this->_createTimestamp();

}

Event::Event(const int id)
{

	this->id = id;

	this->_createTimestamp();

}

Event::Event(const Event &object)
{

	this->operator=(object);

}

Event& Event::operator=(const Event &object)
{

	this->id = object.id;

	int count = object.getCountKV();

	for (int i = 0; i < count; i++)
	{

		this->push_back(object.getKey(i), object.getValue(i));

	}

	return *this;

}

KeyValue* Event::push_back(const std::string Key, const std::string Value)
{

	this->_parametres.push_back(KeyValue(Key, Value));

	return &this->_parametres[this->_parametres.size() - 1];

}

KeyValue* Event::getKV(const std::string Key, const std::string Value)
{

	int count = this->_parametres.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_parametres[i].Key == Key
			&& this->_parametres[i].Value == Value)
		{
			return &this->_parametres[i];
		}

	}

	return nullptr;

}

KeyValue* Event::getKV(const int i)
{

	return this->operator[](i);

}

KeyValue* Event::operator[](const int i)
{

	if (i < 0
		|| i >= this->_parametres.size())
		return nullptr;

	return &this->_parametres[i];

}

int Event::getCountKV() const
{

	return this->_parametres.size();

}

KeyValue* Event::setValue(const std::string Key, const std::string Value)
{

	this->_parametres.push_back(KeyValue(Key, Value));

	return &this->_parametres[this->_parametres.size() - 1];

}

std::string Event::operator[](const std::string Key) const
{

	return this->getValue(Key);

}

std::string Event::getValue(const std::string Key) const
{

	int count = this->_parametres.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_parametres[i].Key == Key)
		{
			return this->_parametres[i].Value;
		}

	}

	return "";

}

std::string Event::getValue(const int i) const
{

	if (i < 0
		|| i >= this->_parametres.size())
		return "";

	return this->_parametres[i].Value;

}

std::string Event::getKey(const int i) const
{

	if (i < 0
		|| i >= this->_parametres.size())
		return "";

	return this->_parametres[i].Key;

}

KeyValue* Event::removeValue(const std::string Value)
{

	int count = this->_parametres.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_parametres[i].Value == Value)
		{
			return &this->_parametres[i];
		}

	}

	return nullptr;

}

KeyValue* Event::removeKey(const std::string Key)
{

	int count = this->_parametres.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_parametres[i].Key == Key)
		{
			return &this->_parametres[i];
		}

	}

	return nullptr;

}

KeyValue* Event::removeKeyValue(const std::string Key, const std::string Value)
{
	
	int count = this->_parametres.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_parametres[i].Value == Value
			&& this->_parametres[i].Key == Key)
		{
			return &this->_parametres[i];
		}

	}

	return nullptr;

}

KeyValue* Event::removeKeyValue(const KeyValue &keyvalue)
{

	return this->removeKeyValue(keyvalue.Key, keyvalue.Value);

}

std::string Event::toString() const
{

	int i = 0;
	int count = this->_parametres.size();

	if (count <= 0)
		return "";

	std::string result = "";

	while (i < count - 1)
	{
		result += this->_parametres[i].toString() + ", ";
		i++;
	}

	result += this->_parametres[i].toString();

	return result;

}

std::string Event::toXML() const
{

	std::string result = "";
	
	result += "<Event>";

	result += "<id>";
	result += this->id;
	result += "</id>";
	
	result += "<Parametres>";

	for (int i = 0; i < this->_parametres.size(); i++)
	{

		result += this->_parametres[i].toXML();

	}

	result += "</Parametres>";

	result += "</Event>";


	return result;

}

std::string Event::toJSON() const
{

	std::string result = "";

	return result;

}

std::string Event::toCSV() const
{

	std::string result = "";

	return result;

}