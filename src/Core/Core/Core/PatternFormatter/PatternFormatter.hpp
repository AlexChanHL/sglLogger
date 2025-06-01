#pragma once

#include "Base.hpp"
#include "Core/utils/Time.hpp"
#include "Core/utils/FileUtility.hpp"

#include <fmt/format.h>


namespace sglLogger
{

enum class PatternKeyType
{
    None = 1,
    Common = 1 << 1,
    Date = 2 << 1,
    Source = 3 << 1,
    File = 4 << 1,
    Line = 5 << 1,
    Level = 6 << 1,

};

class PatternKey
{
    public:
     PatternKey()
     {

     }
     virtual ~PatternKey()
     {

     }

     virtual void appendData(char charData) = 0;
     virtual void appendData(String data) = 0;

     virtual PatternKeyType type() const = 0;
     virtual String data() const = 0;

    private:
};

class CommonPatternKey : public PatternKey
{
    public:
     CommonPatternKey()
     {

     }
     ~CommonPatternKey()
     {

     }
     virtual void appendData(char charData) override
     {
     m_data.push_back(charData);
     }
     virtual void appendData(String src) override
     {
     m_data.append(src);
     }

     virtual PatternKeyType type() const override
		 {
     return PatternKeyType::Common;
     }
     virtual String data() const override
     {
     return m_data;
     }

    private:
     String m_data;
};

class DatePatternKey : public PatternKey
{
    public:
     DatePatternKey()
     {

     }
     ~DatePatternKey()
     {

     }
     virtual void appendData(char charData) override
     {
     m_data.push_back(charData);
     }
     virtual void appendData(String src) override
     {
     m_data.append(src);
     }

     virtual PatternKeyType type() const override
		 {
     return PatternKeyType::Date;
     }
     virtual String data() const override
     {
     return m_data;
     }

    private:
     String m_data;
};

class SourcePatternKey : public PatternKey
{
    public:
     SourcePatternKey()
     {

     }
     ~SourcePatternKey()
     {

     }
     virtual void appendData(char charData) override
     {
     m_data.push_back(charData);
     }
     virtual void appendData(String src) override
     {
     m_data.append(src);
     }

     virtual PatternKeyType type() const override
		 {
     return PatternKeyType::Source;
     }
     virtual String data() const override
     {
     return m_data;
     }

    private:
     String m_data;
};

class FilePatternKey : public PatternKey
{
    public:
     FilePatternKey()
     {

     }
     ~FilePatternKey()
     {

     }
     virtual void appendData(char charData) override
     {
     m_data.push_back(charData);
     }
     virtual void appendData(String src) override
     {
     m_data.append(src);
     }

     virtual PatternKeyType type() const override
		 {
     return PatternKeyType::File;
     }
     virtual String data() const override
     {
     return m_data;
     }

    private:
     String m_data;
};

class LinePatternKey : public PatternKey
{
    public:
     LinePatternKey()
     {

     }
     ~LinePatternKey()
     {

     }
     virtual void appendData(char charData) override
     {
     m_data.push_back(charData);
     }
     virtual void appendData(String src) override
     {
     m_data.append(src);
     }

     virtual PatternKeyType type() const override
		 {
     return PatternKeyType::Line;
     }
     virtual String data() const override
     {
     return m_data;
     }

    private:
     String m_data;
};

class LevelPatternKey : public PatternKey
{
    public:
     LevelPatternKey()
     {

     }
     ~LevelPatternKey()
     {

     }
     virtual void appendData(char charData) override
     {
     m_data.push_back(charData);
     }
     virtual void appendData(String src) override
     {
     m_data.append(src);
     }

     virtual PatternKeyType type() const override
		 {
     return PatternKeyType::Level;
     }
     virtual String data() const override
     {
     return m_data;
     }

    private:
     String m_data;
};


inline SharedPtr<PatternKey> findKey(char key)
{
    switch(key)
    {
    case 'd':
    return createShared<DatePatternKey>();
    case 's':
    return createShared<SourcePatternKey>();
    case 'f':
    return createShared<FilePatternKey>();
    case 'l':
    return createShared<LinePatternKey>();
    case 'L':
    return createShared<LevelPatternKey>();
    default:
    return createShared<CommonPatternKey>();
    }

    return createShared<CommonPatternKey>();
}

inline String matchKeyMsg(LogMsg logMsg, PatternKeyType type, String data)
{
    switch(type)
    {
    case PatternKeyType::Common:
    return data;
    case PatternKeyType::Date:
    {
		TimeType time = logMsg.time();
		data.append(utils::formatStringTime(time));
    return data;
    }
    case PatternKeyType::Source:
		data.append(logMsg.payload());
    return data;
    case PatternKeyType::File:
		data.append(fmt::format("{}", logMsg.filteredFileName()));
    return data;
    case PatternKeyType::Line:
		data.append(fmt::format("Line -- {}", logMsg.line()));
    return data;
    case PatternKeyType::Level:
		data.append(logMsg.level());
    return data;
	  default:
    return "";
    }

    return "";
}

class PatternFormatter
{
    public:
     PatternFormatter()
     {

     }
     ~PatternFormatter()
     {

     }

  	 void setPattern(StringView pattern)
     {
     m_pattern = pattern;

     for(u64_t i = 0; i < m_pattern.size(); i++)
     {
     SharedPtr<PatternKey> key = nullptr;
     switch(m_pattern[i])
     {
     case '$':
     i++;
     if(i < m_pattern.size())
     {
     key = findKey(m_pattern[i]);
     m_patternKeys.push_back(key);
     }
     break;
     default:
     key = createShared<CommonPatternKey>();
		 for(;i < m_pattern.size();i++)
     {
     key->appendData(m_pattern[i]);
     if(((i + 1) < m_pattern.size()) && (m_pattern[i + 1] == '$'))
     {
     break;
     }
     }

     m_patternKeys.push_back(key);
     break;
     }

     }

     }

  	 void set(LogMsg logMsg, String& data)
     {
     for(SharedPtr<PatternKey> key : m_patternKeys)
     {
     String keyData = matchKeyMsg(logMsg, key->type(), key->data());
     data.append(keyData);
     }

     std::cout << data << '\n';
     }
    
    private:
     String m_pattern;
     Vector<SharedPtr<PatternKey>> m_patternKeys;
};

}       // namespace sglLogger

