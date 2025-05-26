
#include "sglLogger/Logger.hpp"
#include "sglLogger/RouteMethod.hpp"
#include "sglLogger/RouteMethod/RouteStdOut.hpp"


int main()
{
		auto logger = std::make_unique<sglLogger::Logger>();

    auto stdoutRoute = std::make_unique<sglLogger::RouteStdOut>();

    logger->setRootFile("/Users/alexchan_1/Project Files/C++/C++ ActiveProjects/sglLogger/");

  	logger->setRouteMethod(std::move(stdoutRoute));

    // Date - Payload - File - Line - Level
    logger->setPattern("|$d| --$s-- |$f| |$l| |$L|");

  	logger->infoLog("Model add");
  	logger->infoLog(sglLogger::SourceData(__FILE__, __LINE__), "Model add");
}

