#pragma once
#include<string>
class xconfig
{
public:
	enum out
	{
		console,file
	};
	out output = console;
	std::string filename = "log.txt";
};

