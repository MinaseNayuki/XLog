#pragma once
#include<string>
class LogOutput
{
public:
	virtual void write(const std::string& mesg) = 0;
	virtual ~LogOutput(){}
};