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
        void changeDate(const Date& newDate) {
            this->d = newDate;
        }
        void SetLogLevel(Level level) {
            m_LogLevel = level;
        }
      
        template<typename... Args>
        void Warn(const String& message,Args... args) {
            if (m_LogLevel >= LevelWarning) {
                std::cout << "[Warning]: " << message;
                //std::cout << Date::cache << std::endl;
                std::cout << "Date: ";
                d.getCache();
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template< typename... Args>
        void Error(const String& message, Args... args) {
            if (m_LogLevel >= LevelError) {
                std::cout << "[Error]: " << message;
                std::cout << "Date: ";
                d.getCache();
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template<typename... Args>
        void Info(const String& message,Args... args) {
            if (m_LogLevel >= LevelInfo) {
                std::cout << "[Info]: " << message;
                std::cout << "Date: ";
                d.getCache();
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template <typename T, typename... Types>
        void print(T var1, Types... var2)
        {
            std::cout << var1 << " ";

            print(var2...);
        }

        void print()
        {
           // std::cout << "Last call for print function\n";
                
        }

    };
}
#endif

