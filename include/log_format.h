#pragma once
#include<string>
enum Level
{
	debug, info, error, fatal
};
class LogFormat
{
public:
	virtual std::string Format(int level, const std::string& name, const std::string& file, int line) = 0;
};