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
	if (a.output == xconfig::console)
	{
		logger_ = (*new logger(new xlog_format, new log_console_output));
	}
	else
	{
		logger_ = (*new logger(new xlog_format, new log_fileoutput(a.filename)));
	}
}
logger& log_fac::getlogger()
{
	return logger_;
}
