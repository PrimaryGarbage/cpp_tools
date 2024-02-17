#ifndef __TIME_TOOLS_HPP__
#define __TIME_TOOLS_HPP__

#include <string>
#include <chrono>
#include <ctime>

namespace prim
{
    inline std::string currentDateTimeString(const char* format = "%d-%m-%Y %H:%M:%S")
    {
        std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string timeStr(30, '\0');
        std::strftime(&timeStr[0], timeStr.size(), format, std::localtime(&time));
        return timeStr;
    }
}

#endif // __TIME_TOOLS_HPP__