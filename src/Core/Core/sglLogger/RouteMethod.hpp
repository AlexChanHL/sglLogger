#pragma once

#include "Core/LogMsg.hpp"


namespace sglLogger
{

class RouteMethod
{
    public:
     RouteMethod() = default;
     virtual ~RouteMethod() = default;
     virtual void use(const LogMsg& logMsg) = 0;
    
    private:
};

}      // namespace sglLogger

