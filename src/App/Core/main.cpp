
#include "sglLogger/Logger.hpp"

#include <iostream>


int main()
{
		auto logger = sglLogger::Logger();

  	// logger.setRouteMethod(sglLogger::Stdout);

    // Date - Payload - File - Line - Level
    // logger.setLogPattern("$d $s $f $l $L");

    logger->infoLog("Model add");
}

