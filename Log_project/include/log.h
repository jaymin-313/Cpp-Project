#include"date.h"
#include"string.h"
using namespace utility;
#ifndef LOG_H 
#define LOG_H 
namespace logging {
 
    class Log {

    public:
        enum Level {
            LevelError = 0, LevelWarning, LevelInfo
        };
    private:
        Level m_LogLevel;
        utility::Date d;
    public:
        Log() {
            m_LogLevel = LevelError;
            
        }
        Log(Level l1,utility::Date d1) {
            m_LogLevel = l1;
            d = d1;
        }

        void SetLogLevel(Level level);
        void Warn(const String& message);
   
        void Error(const String& message);
        void Info(const String& message);
    };
}
#endif

