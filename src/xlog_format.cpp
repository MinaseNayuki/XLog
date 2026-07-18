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
    // 获取当前时间
    time_t now = time(nullptr);

    // 转换成本地时间
    tm* local = localtime(&now);

    // 格式化
    std::stringstream ss;

    ss << std::setfill('0')
        << local->tm_year + 1900 << "-"
        << std::setw(2) << local->tm_mon + 1 << "-"
        << std::setw(2) << local->tm_mday << " "
        << std::setw(2) << local->tm_hour << ":"
        << std::setw(2) << local->tm_min << ":"
        << std::setw(2) << local->tm_sec;

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