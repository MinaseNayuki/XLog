#pragma once
#include"logger.h"
#include"xconfig.h"
#define LOGDEBUG(s) log_fac::instance().getlogger().Log(debug,s,__FILE__,__LINE__)
#define LOGINFO(s)	log_fac::instance().getlogger().Log(info,s,__FILE__,__LINE__)
#define LOGERROR(s)	log_fac::instance().getlogger().Log(error,s,__FILE__,__LINE__)
#define LOGFATAL(s)	log_fac::instance().getlogger().Log(fatal,s,__FILE__,__LINE__)
class log_fac
{
public:
	log_fac();
	static log_fac& instance();
	void init(const xconfig& a);
	logger& getlogger();
private:
	logger logger_;
};

