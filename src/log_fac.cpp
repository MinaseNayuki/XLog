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
			logger_.init(make_unique<xlog_format>(), make_unique<log_console_output>());
		}
		else
		{
			logger_.init(make_unique<xlog_format>(), make_unique<log_fileoutput>(a.filename));
		}
	}
	else
	{
		if (a.output == xconfig::console)
		{
			logger_.init(make_unique<xml_format>(), make_unique<log_console_output>());
		}
		else
		{
			logger_.init(make_unique<xml_format>(), make_unique<log_fileoutput>(a.filename));
		}
	}
}
logger& log_fac::getlogger()
{
	return logger_;
}
