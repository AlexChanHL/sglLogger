#pragma once

#include "Base.hpp"


namespace sglLogger
{

namespace utils
{

inline String filterRoot(String fileName, u64_t rootLength)
{
    return fileName.substr(rootLength, fileName.size());
}

}     // namespace utils

}    // namespace sglLogger

