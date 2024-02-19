#include"date.h"
#include"string.h"
using namespace utility;
#ifndef LOG_H 
#define LOG_H 
#include<fstream>
#include<iostream>
namespace logging {
 
    class Log {

    public:
        enum Level {
            LevelError = 0, LevelWarning, LevelInfo
        };
    private:
        Level m_LogLevel = LevelError;
        Date d;
        String fileName{ "database.txt" };
        String output;
    public:
        
        Log(Level l1, Date d1) :m_LogLevel{ l1 }, d{ d1 } { }

        void changeDate(const Date& newDate) {
            this->d = newDate;
        }
        void SetLogLevel(Level level) {
            this->m_LogLevel = level;
        }
      
        template<typename... Args>
        void Warn(const String& message,Args... args) {
            if (m_LogLevel >= LevelWarning) {
                String output;
                std::cout << "[";

                d.getCache();
                d.dumpCache(fileName);
                std::cout << "]";
                std::cout << "[Warning]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
                output = output + " Warning: " + message;
                dumpToFile(output);
            }
        }
        template< typename... Args>
        void Error(const String& message, Args... args) {
            if (m_LogLevel >= LevelError) {
                String output;
                std::cout << "[";
                d.getCache();
                d.dumpCache(fileName);
                std::cout << "]";
                std::cout << "[Error]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
                output = output + " Error: " + message;
                dumpToFile(output);
                
            }
        }
        template<typename... Args>
        void Info(const String& message,Args... args) {
            if (m_LogLevel >= LevelInfo) {
                String output;
                std::cout << "[";
                d.getCache();
                d.dumpCache(fileName);
                std::cout << "]";
                std::cout << " [Info]: " << message;
                std::cout << " ";
                output = output + " Info: " + message;
                dumpToFile(output);
                print(args...);
                std::cout << std::endl;
            }
        }
        template <typename T, typename... Types>
        void print(T var1, Types... var2)
        {
            std::cout << var1 << " ";
            dumpToFile(var1);
            dumpToFile(" ");
            print(var2...);
        }

       
        void print()
        {
           // std::cout << "Last call for print function\n";
                
        }
        template<typename T>
        int dumpToFile(T& s) {
            std::ofstream of;
            std::fstream f;
            of.open(fileName.getCharString(), std::ios::app);
                // If we couldn't open the output file stream for writing 
                if (!of)
                {
                    // Print an error and exit 
                    std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
                    return 1;
            
                }
            
                // We'll write Cache into this file 
                
                of << s;
                of.close();
                return 0;
        }
    };
}
#endif

