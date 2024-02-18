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
        Level m_LogLevel = LevelError;
        Date d;
    public:
        
        Log(Level l1, Date d1) :m_LogLevel{ l1 }, d{d1} { }

        void changeDate(const Date& newDate) {
            this->d = newDate;
        }
        void SetLogLevel(Level level) {
            this->m_LogLevel = level;
        }
      
        template<typename... Args>
        void Warn(const String& message,Args... args) {
            if (m_LogLevel >= LevelWarning) {
                
                std::cout << "[";
                d.getCache();
                std::cout << "]";
                std::cout << "[Warning]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template< typename... Args>
        void Error(const String& message, Args... args) {
            if (m_LogLevel >= LevelError) {
                
                std::cout << "[";
                d.getCache();
                std::cout << "]";
                std::cout << "[Error]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template<typename... Args>
        void Info(const String& message,Args... args) {
            if (m_LogLevel >= LevelInfo) {
                
                std::cout << "[";
                d.getCache();
                std::cout << "]";
                std::cout << " [Info]: " << message;
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

