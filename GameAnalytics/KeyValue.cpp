#include "KayValue.h"

KeyValue::KeyValue()
{

	this->setKeyValue("", "");

}

KeyValue::KeyValue(const std::string Key, const std::string Value)
{
	
	this->setKeyValue(Key, Value);

}

KeyValue::KeyValue(const KeyValue &object)
{

	this->operator=(object);

}

KeyValue& KeyValue::setKeyValue(const std::string Key, const std::string Value)
{

	this->Key = Key;
	this->Value = Value;

	return *this;

}

KeyValue& KeyValue::operator[](std::string Key)
{

	this->Key = Key;

	return *this;

}

KeyValue& KeyValue::operator=(const std::string Value)
{

	this->Value = Value;

	return *this;

}

KeyValue& KeyValue::operator=(const KeyValue &object)
{

	this->Key = object.Key;
	this->Value = object.Value;

	return *this;

}

std::string KeyValue::toString() const
{

	return "\"" + this->Key + "\":\"" + this->Value + "\"";

}