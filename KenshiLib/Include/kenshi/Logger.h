#pragma once

#include <string>

class Logger
{
public:
    enum Severity
    {
        Trace,
        Debug,
        Info,
        Warning,
        Error,
        Fatal
    };

    static void init();// public RVA = 0x17F740
    static void close();// public RVA = 0x17F170
    static void logMessage(const std::string& message, Logger::Severity severity);// public RVA = 0x17F210
    static void logMessageDebug(const std::string& message);// public RVA = 0x17F150
    static void logHeader();// private RVA = 0x17F440
};