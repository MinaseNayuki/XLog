#include "log_fac.h"
using namespace std;
log_fac::log_fac(){}
log_fac& log_fac::instance()
{
	static log_fac single;
	return single;
}
void log_fac::init(const xconfig& a)
{
	if (a.type == xconfig::normal)
	{
		if (a.output == xconfig::console)
		{
			logger_.init(new xlog_format, new log_console_output);
		}
		else
		{
			logger_.init(new xlog_format, new log_console_output);
		}
	}
	else
	{
		if (a.output == xconfig::console)
		{
			logger_.init(new xml_format, new log_console_output);
		}
		else
		{
			logger_.init(new xml_format, new log_console_output);
		}
	}
}
logger& log_fac::getlogger()
{
	return logger_;
}
