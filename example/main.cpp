#include"log_fac.h"
#include"xconfig.h"
int main()
{
	xconfig a;
	a.output = xconfig::console;
	a.filename = "qqqqqqq.txt";
	log_fac::instance().init(a);
	LOGDEBUG("debugtxt");
	LOGINFO("1111");
}
