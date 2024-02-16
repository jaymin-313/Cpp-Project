#include "..\include\log.h" 
#include"..\include\string.h"
#include"..\include\date.h"
#include <iostream> 
using namespace logging;
using namespace utility;
void Log::SetLogLevel(Level level) {
    m_LogLevel = level;
}

void Log::Warn(const String& message) {
    if (m_LogLevel >= LevelWarning) {
        std::cout << "[Warning]: " << message ;
        //std::cout << cache << std::endl;
        d.getCache();
        std::cout << std::endl;
    }
}

void Log::Error(const String& message) {
    if (m_LogLevel >= LevelError) {
        std::cout << "[Error]: " << message ;
        d.getCache();
        std::cout << std::endl;
    }
}

void Log::Info(const String& message) {
    if (m_LogLevel >= LevelInfo) {
        std::cout << "[Info]: " << message;
        d.getCache();
        std::cout << std::endl;
    }
}
