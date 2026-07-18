#pragma once
#include "log_output.h"
#include<fstream>
class log_fileoutput :public LogOutput
{
public:
	log_fileoutput(const std::string& filename);
	void write(const std::string& mesg)override;
private:
	std::fstream fw;
};

