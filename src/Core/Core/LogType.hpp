#pragma once

#include "Base.hpp"


namespace sglLogger
{

enum class LogType
{
    None = 1,
    Trace =  2 << 1,
    Debug = 3 << 1, 
    Info = 4 << 1, 
    Warn = 5 << 1, 
    Error = 6 << 1, 
    Servere = 7 << 1
};

inline String stringLogType(LogType logType)
{
    switch(logType)
    {
		case LogType::Trace:
    return "Trace";
    case LogType::Debug:
    return "Debug";
		case LogType::Info:
    return "Info";
    case LogType::Warn:
    return "Warn";
    case LogType::Error:
    return "Error";
    case LogType::Servere:
    return "Servere";
    default:
    return "";
    }

    return "";
}

}      // namespace sglLogger

