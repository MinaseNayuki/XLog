#include "logger.h"
#include<stdexcept>
#include<utility>
using namespace std;
logger::logger(){}
void logger::init(std::unique_ptr<LogFormat> fmt, std::unique_ptr<LogOutput> out)
{
	format = std::move(fmt), output = std::move(out);
}
void logger::Log(int level, const std::string& name, const std::string& file, int line)
{
	if (!format || !output)
	{
		throw logic_error("logger is not initialized");
	}
	string s = format->Format(level, name, file, line);
	output->write(s);
}
logger::~logger() = default;
