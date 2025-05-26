#pragma once

#include "sglLogger/RouteMethod.hpp"
#include "Base.hpp"


namespace sglLogger
{

class RouteStdOut : public RouteMethod
{
    public:
     RouteStdOut()
     {

     }
     virtual ~RouteStdOut()
     {

     }
     virtual void use(const LogMsg& logMsg) override
     {
     FILE* file = stdout;
     String data = "Model add";
     fwrite(data.data(), sizeof(char), data.size(), file);

 	 	 fflush(file);
     }

    private:
};

}

