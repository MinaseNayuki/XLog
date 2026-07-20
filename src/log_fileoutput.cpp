#include "log_fileoutput.h"
#include<iostream>
#include<stdexcept>
using namespace std;
log_fileoutput::log_fileoutput(const std::string& filename) :fw(filename, ios::app)
{
	if (!fw.is_open()) { throw runtime_error("failed to open file: " + filename); }
}
void log_fileoutput::write(const std::string& mesg)
{
	fw << mesg << '\n';
}
