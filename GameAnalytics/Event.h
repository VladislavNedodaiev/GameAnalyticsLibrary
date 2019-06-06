#pragma once

#include "KayValue.h"

#include <vector>
#include <ctime>

class Event : public Stringable
{

	std::vector <KeyValue> _keyvalues;

	void _createTimestamp();

public:

	int id;

	Event();
	Event(const int id);
	
	KeyValue* push_back(const std::string Key, const std::string Value);

	KeyValue* getKV(const std::string Key, const std::string Value);
	KeyValue* getKV(const int i);
	
	// get count of keyvalue pairs
	int getCountKV() const;

	KeyValue* setValue(const std::string Key, const std::string Value);
	std::string operator[](const std::string Key) const;
	std::string operator[](const int i) const;
	std::string getValue(const std::string Key) const;
	std::string getValue(const int i) const;

	KeyValue* removeValue(const std::string Value);
	KeyValue* removeKey(const std::string Key);

	KeyValue* removeKeyValue(const std::string Key, const std::string Value);
	KeyValue* removeKeyValue(const KeyValue &keyvalue);

	// each key-value pair is separated with comma
	std::string toString() const;

};