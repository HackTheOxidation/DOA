#pragma once
#include <string>

class OAHashMapException : public std::exception
{
	std::string description;

public:
	OAHashMapException(std::string descr = "OAHashMap exception") : description(descr)
	{}

	const char* what() const override
	{
		return description.c_str();
	}
};
