#pragma once
#include"log_format.h"
#include"xlog_format.h"
#include"log_console_output.h"
#include"log_fileoutput.h"
#include"xml_format.h"
#include<memory>
class logger
{
public:
	logger();
	void init(std::unique_ptr<LogFormat> fmt, std::unique_ptr<LogOutput> out);
	void Log(int level, const std::string& name, const std::string& file, int line);
	~logger();
private:
	std::unique_ptr<LogFormat> format;
	std::unique_ptr<LogOutput> output;
};

