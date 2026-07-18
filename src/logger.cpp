#include "logger.h"
#include<iostream>
using namespace std;
logger::logger(){}
logger::logger(xlog_format* fmt, LogOutput* out) :format(fmt), output(out){}
void logger::Log(int level, const std::string& name, const std::string& file, int line)
{
	string s = format->Format(level, name, file, line);
	output->write(s);
}
logger::~logger()
{
	delete format; format = nullptr;
	delete output; output = nullptr;
}