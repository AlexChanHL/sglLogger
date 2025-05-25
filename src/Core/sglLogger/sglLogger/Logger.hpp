#pragma once

#include "Base.hpp"

#include "Logger/Logger.hpp"


namespace sglLogger
{

enum class LogType
{
    None = 1,
    Trace = 1 << 1, 
    Debug = 2 << 1, 
    Info = 3 << 1, 
    Warn = 4 << 1, 
    Error = 5 << 1, 
    Servere = 6 << 1
};

class Logger
{
   public:
    Logger();
    ~Logger();

    void traceLog();
    void debugLog();
    template<typename... Args>
    void infoLog(Args&&... args);
    void warnLog();
    void errorLog();
    void servereLog();

   private:
    void log(String payload, LogType logType);

   private:
};

}     // namespace sglLogger

