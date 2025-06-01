#pragma once

#include "Base.hpp"

#include <fmt/format.h>


namespace sglLogger
{

namespace utils
{

inline String formatStringTime(const TimeType& time)
{
     TmType* tm = std::localtime(&time);

     String dest;
    
     dest.append(fmt::format("{}", (tm->tm_year + 1900)));
     dest.append("-");
     dest.append(fmt::format("{}", (tm->tm_mon + 1)));
     dest.append("-");
     dest.append(fmt::format("{}", tm->tm_mday));
     dest.append(" ");
     dest.append(fmt::format("{}", tm->tm_hour));
     dest.append("-");
     dest.append(fmt::format("{}", tm->tm_min));
     dest.append("-");
     dest.append(fmt::format("{}", tm->tm_sec));

     return dest;
}

}   // namespace utils

}    // namespace sglLogger

