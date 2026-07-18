#include "log_console_output.h"
#include<iostream>
#include<string>
using namespace std;

void log_console_output::write(const std::string& mesg) { cout << mesg << endl; }