#pragma once
#include "log_output.h"
#include<string>
class log_console_output :public LogOutput
{
public:
	void write(const std::string& mesg)override;
};

