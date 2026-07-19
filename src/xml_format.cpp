#include"xml_format.h"
#include<sstream>
using namespace std;
string xml_format::Format(int x, const std::string& name, const std::string& file, int line)
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
    std::stringstream ss;
    ss << "<log>\n";
    ss << "\t<level>"
        << level
        << "</level>\n";
    ss << "\t<message>"
        << name
        << "</message>\n";
    ss << "\t<file>"
        << file
        << "</file>\n";
    ss << "\t<line>"
        << line
        << "</line>\n";
    ss << "</log>";
    return ss.str();
}