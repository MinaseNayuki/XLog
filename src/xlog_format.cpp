#define _CRT_SECURE_NO_WARNINGS
#include "xlog_format.h"
#include<string>
#include<iostream>
#include<sstream>
#include<ctime>
#include<iomanip>
using namespace std;
string GetCurrentTime()
{
    // Get current local time.
    time_t now = time(nullptr);

    // Use a thread-safe localtime conversion.
    tm local{};
#ifdef _WIN32
    localtime_s(&local, &now);
#else
    localtime_r(&now, &local);
#endif

    // Format as yyyy-mm-dd hh:mm:ss.
    std::stringstream ss;

    ss << std::setfill('0')
        << local.tm_year + 1900 << "-"
        << std::setw(2) << local.tm_mon + 1 << "-"
        << std::setw(2) << local.tm_mday << " "
        << std::setw(2) << local.tm_hour << ":"
        << std::setw(2) << local.tm_min << ":"
        << std::setw(2) << local.tm_sec;

    return ss.str();
}
string xlog_format::Format(int x, const std::string& name, const std::string& file, int line)
{
    string level;
    switch (x)
    {
    case debug:level = "debug";
        break;
    case info:level = "info";
        break;
    case error:level = "error";
        break;
    case fatal:level = "fatal";
        break;
    }
    string s;
	s += GetCurrentTime() + " " + level + " " + name + ":" + file + " " + to_string(line);
    return s;
}
