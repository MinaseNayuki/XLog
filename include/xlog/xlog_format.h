#pragma once
#include"log_format.h"
enum Level
{
	debug, info, error, fatal
};
class xlog_format:public LogFormat
{
public:
	std::string Format(int level, const std::string& name, const std::string& file, int line);
};

