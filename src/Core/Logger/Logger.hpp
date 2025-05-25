#pragma once


class Logger
{
   public:
    Logger() = default;
    virtual ~Logger() = default;

    virtual void traceLog() = 0;
    virtual void debugLog() = 0;

    virtual void infoLog() = 0;
    virtual void warnLog() = 0;
    virtual void errorLog() = 0;
    virtual void servereLog() = 0;
   private:
};

