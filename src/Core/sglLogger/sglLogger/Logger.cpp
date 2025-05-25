
#include "Core/LogMsg.hpp"
#include "Core/Types.hpp"
#include "Base.hpp"
#include "Logger.hpp"

#include <fmt/format.h>


namespace sglLogger
{

class Logger
{
   public:
    Logger()
    {

    }
    ~Logger()
    {

    }

    void traceLog() 
    {
    // log(payload, LogType::Trace);
    }

    void debugLog() 
		{
    // log(payload, LogType::Trace);
    }

    template<typename... Args>
    void infoLog(Args&&... args) 
		{
    // String data = fmt::format("{}\n", "0");
    }

    void warnLog() 
		{

    }

    void errorLog() 
		{

    }

    void servereLog() 
		{

    }

   private:
    void log(String payload, LogType logType)
    {
    // LogMsg logMsg = createMsg(payload, logType);
    // m_routeMethod->use(logMsg);
    }

   private:
		LogMsg m_lastLogMessage;
    // UniquePtr<RouteMethod> m_routeMethod;
};

}       // namespace sglLogger

