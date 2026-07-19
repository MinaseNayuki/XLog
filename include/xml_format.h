#include"log_format.h"
class xml_format :public LogFormat
{
	std::string Format(int level, const std::string& name, const std::string& file, int line)override;
};