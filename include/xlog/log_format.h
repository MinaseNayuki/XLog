#pragma once
#include<string>
class LogFormat
{
public:
	virtual std::string Format(int level, const std::string& name, const std::string& file, int line) = 0;
};