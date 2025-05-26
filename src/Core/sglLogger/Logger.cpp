
#include "Core/Types.hpp"
#include "Core/LogType.hpp"
#include "Base.hpp"
#include "Logger.hpp"


namespace sglLogger
{

Logger::Logger()
{

}
Logger::~Logger()
{

}

void Logger::log(StringView payload, LogType logType, SourceData sourceData)
{
  	LogMsg logMsg = LogMsg(payload, logType, sourceData);

    String data;
	  m_patternFormatter.set(logMsg, data);

    // m_routeMethod->use(data);

  	// for(SharedPtr<RouteMethod> method : m_routeMethods)
    // {
    // method->use(data);
    // }
}

}       // namespace sglLogger

