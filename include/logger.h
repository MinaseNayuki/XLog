#pragma once
#include"log_format.h"
#include"xlog_format.h"
#include"log_console_output.h"
#include"log_fileoutput.h"
#include"xml_format.h"
class logger
{
public:
	logger();
	void init(LogFormat* fmt, LogOutput* out);
	void Log(int level, const std::string& name, const std::string& file, int line);
	~logger();
private:
	LogFormat* format;
	LogOutput* output;
};

