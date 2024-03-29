#pragma once

#include "Stringable.h"
#include "Serializable.h"

struct KeyValue : public Stringable, public Serializable
{

	std::string Key;
	std::string Value;

	KeyValue();
	KeyValue(const std::string Key, const std::string Value);
	KeyValue(const KeyValue &object);

	KeyValue& setKeyValue(const std::string Key, const std::string Value);

	// operator [] for assigning the value of key
	KeyValue& operator[](const std::string Key);

	// operator = for assigning the value of value
	KeyValue& operator=(const std::string Value);

	// operator = for assigning both key and value
	KeyValue& operator=(const KeyValue &object);

	// return value is represented in following format: "Key":"Value"
	std::string toString() const;
	std::string toXML() const;
	std::string toJSON() const;
	std::string toCSV() const;

};
