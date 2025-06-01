#pragma once

#include "Core/PreProcessData.hpp"
#include "Core/LogMsg.hpp"
#include "Core/PatternFormatter/PatternFormatter.hpp"
#include "Base.hpp"
#include "sglLogger/RouteMethod.hpp"

#include <fmt/format.h>


namespace sglLogger
{

class Logger
{
   public:
    Logger();
    ~Logger();

		void setRootFile(const String& rootFile)
    {
    m_rootFile = rootFile;
    }

		void setRouteMethod(UniquePtr<RouteMethod> routeMethod)
    {
    m_routeMethod = std::move(routeMethod);
    }

    void setPattern(StringView pattern)
    {
    m_patternFormatter.setPattern(pattern);
    }

    template<typename... Args>
    void traceLog(StringView format, Args&&... args)
    {
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
        log(data, LogType::Trace, SourceData());
    }
    template<typename... Args>
    void traceLog(SourceData sourceData, StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
  			sourceData.m_rootFile = m_rootFile;
        log(data, LogType::Trace, sourceData);
		}
    template<typename... Args>
    void debugLog(StringView format, Args&&... args)
    {
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
        log(data, LogType::Debug, SourceData());
    }
    template<typename... Args>
		void debugLog(SourceData sourceData, StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
  			sourceData.m_rootFile = m_rootFile;
        log(data, LogType::Debug, sourceData);
		}
    template<typename... Args>
    void infoLog(StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
        log(data, LogType::Info, SourceData());
		}
    template<typename... Args>
    void infoLog(SourceData sourceData, StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
  			sourceData.m_rootFile = m_rootFile;
        log(data, LogType::Info, sourceData);
		}
    template<typename... Args>
    void warnLog(StringView format, Args&&... args)
    {
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
        log(data, LogType::Warn, SourceData());
    }
    template<typename... Args>
		void warnLog(SourceData sourceData, StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
  			sourceData.m_rootFile = m_rootFile;
        log(data, LogType::Warn, sourceData);
		}
    template<typename... Args>
    void errorLog(StringView format, Args&&... args)
    {
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
        log(data, LogType::Error, SourceData());
    }
    template<typename... Args>
		void errorLog(SourceData sourceData, StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
  			sourceData.m_rootFile = m_rootFile;
        log(data, LogType::Error, sourceData);
		}
    template<typename... Args>
    void servereLog(StringView format, Args&&... args)
    {
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
        log(data, LogType::Servere, SourceData());
    }
    template<typename... Args>
		void servereLog(SourceData sourceData, StringView format, Args&&... args)
		{
    		String data = fmt::vformat(format, fmt::make_format_args(args...));
  			sourceData.m_rootFile = m_rootFile;
        log(data, LogType::Servere, sourceData);
		}

   private:
    void log(StringView payload, LogType logType, SourceData sourceData);

   private:
 	  LogMsg m_lastLogMessage;
    PatternFormatter m_patternFormatter;
    UniquePtr<RouteMethod> m_routeMethod;
		String m_rootFile;
};

}     // namespace sglLogger

