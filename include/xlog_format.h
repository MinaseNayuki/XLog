#pragma once
#include"log_format.h"
class xlog_format:public LogFormat
{
public:
	std::string Format(int level, const std::string& name, const std::string& file, int line);
};

