#pragma once

#include "Base.hpp"
#include "Types.hpp"
#include "LogType.hpp"


namespace sglLogger
{

class LogMsg
{
   public:
    LogMsg()
    {

    }
    LogMsg(StringView payload, LogType logType, SourceData sourcedata)
    : m_time{std::time(NULL)},
      m_sourceData{sourcedata},
      m_logType{logType},
      m_payload{payload}
    {

    }
    ~LogMsg()
    {

    }
 
    TimeType time() const
    {
    return m_time;
    }

    String fileName() const
		{
    return m_sourceData.m_file;
    }

    String filteredFileName() const
		{
    return utils::filterRoot(m_sourceData.m_file, m_sourceData.m_rootFile.size());
    }

    i64_t line() const
    {
    return m_sourceData.m_line;
    }

    String level() const
		{
    return stringLogType(m_logType);
    }

    String payload() const
    {
    return m_payload;
    }

   private:
    TimeType m_time;
    SourceData m_sourceData;
    LogType m_logType;
    String m_payload;
};

}     // namespace sglLogger

