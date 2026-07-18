#pragma once
#include"xlog_format.h"
#include"log_console_output.h"
#include"log_fileoutput.h"
class logger
{
public:
	logger();
	logger(xlog_format* fmt, LogOutput* out);
	void Log(int level, const std::string& name, const std::string& file, int line);
	~logger();
private:
	xlog_format* format;
	LogOutput* output;
};

