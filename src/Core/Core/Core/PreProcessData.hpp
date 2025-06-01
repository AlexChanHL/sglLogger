#pragma once

#include "Base.hpp"
#include "Types.hpp"
#include "utils/FileUtility.hpp"


namespace sglLogger
{

class SourceData
{
    public:
     SourceData()
     : m_file{"No file"},
       m_line{-1}
     {

     }
     SourceData(String file, u64_t line)
     : m_file{file},
       m_line{static_cast<i64_t>(line)}
     {

     }
     ~SourceData()
     {

     }

    public:
     String m_file;
     i64_t m_line;
     
     String m_rootFile;
};

};

