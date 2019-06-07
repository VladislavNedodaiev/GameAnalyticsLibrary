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

	this->_keyvalues.push_back(KeyValue("Timestamp", std::string(buffer)));

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

}

KeyValue* Event::push_back(const std::string Key, const std::string Value)
{

	this->_keyvalues.push_back(KeyValue(Key, Value));

	return &this->_keyvalues[this->_keyvalues.size() - 1];

}

KeyValue* Event::getKV(const std::string Key, const std::string Value)
{

	int count = this->_keyvalues.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_keyvalues[i].Key == Key
			&& this->_keyvalues[i].Value == Value)
		{
			return &this->_keyvalues[i];
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
		|| i >= this->_keyvalues.size())
		return nullptr;

	return &this->_keyvalues[i];

}

int Event::getCountKV() const
{

	return this->_keyvalues.size();

}

KeyValue* Event::setValue(const std::string Key, const std::string Value)
{

	this->_keyvalues.push_back(KeyValue(Key, Value));

	return &this->_keyvalues[this->_keyvalues.size() - 1];

}

std::string Event::operator[](const std::string Key) const
{

	return this->getValue(Key);

}

std::string Event::getValue(const std::string Key) const
{

	int count = this->_keyvalues.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_keyvalues[i].Key == Key)
		{
			return this->_keyvalues[i].Value;
		}

	}

	return "";

}

std::string Event::getValue(const int i) const
{

	if (i < 0
		|| i >= this->_keyvalues.size())
		return "";

	return this->_keyvalues[i].Value;

}

std::string Event::getKey(const int i) const
{

	if (i < 0
		|| i >= this->_keyvalues.size())
		return "";

	return this->_keyvalues[i].Key;

}

KeyValue* Event::removeValue(const std::string Value)
{

	int count = this->_keyvalues.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_keyvalues[i].Value == Value)
		{
			return &this->_keyvalues[i];
		}

	}

	return nullptr;

}

KeyValue* Event::removeKey(const std::string Key)
{

	int count = this->_keyvalues.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_keyvalues[i].Key == Key)
		{
			return &this->_keyvalues[i];
		}

	}

	return nullptr;

}

KeyValue* Event::removeKeyValue(const std::string Key, const std::string Value)
{
	
	int count = this->_keyvalues.size();

	for (int i = 0; i < count; i++)
	{

		if (this->_keyvalues[i].Value == Value
			&& this->_keyvalues[i].Key == Key)
		{
			return &this->_keyvalues[i];
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
	int count = this->_keyvalues.size();

	if (count <= 0)
		return "";

	std::string result = "";

	while (i < count - 1)
	{
		result += this->_keyvalues[i].toString() + ", ";
		i++;
	}

	result += this->_keyvalues[i].toString();

	return result;

}