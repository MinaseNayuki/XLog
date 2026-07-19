#pragma once
#include<string>
class xconfig
{
public:
	enum out
	{
		console,file
	};
	enum texttype
	{
		normal, xml
	};
	out output = console;
	texttype type = normal;
	std::string filename = "log.txt";
};

