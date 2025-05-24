
#include "Core/LogMsg.hpp"
#include "Core/Types.hpp"
#include "Core/Base.hpp"
#include "Logger.hpp"

#include <fmt/format.h>


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

class LoggerImpl : public Logger
{
   public:
    LoggerImpl()
    {

    }
    virtual ~LoggerImpl()
    {

    }

    virtual void traceLog() override
    {
    // log(payload, LogType::Trace);
    }

    virtual void debugLog() override
		{
    // log(payload, LogType::Trace);
    }

    virtual void infoLog() override
		{

    }

    virtual void warnLog() override
		{

    }

    virtual void errorLog() override
		{

    }

    virtual void servereLog() override
		{

    }

   private:
    void log()
    {
    
    }

   private:
		LogMsg m_lastLogMessage;
};

static UniquePtr<Logger> createSglLogger()
{
    return createUnique<LoggerImpl>();
}

}       // namespace sglLogger

