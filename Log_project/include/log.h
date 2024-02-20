#include"date.h"
#include"string.h"
using namespace utility;
#ifndef LOG_H 
#define LOG_H 
#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>

#include<string>
namespace logging {
 
    class Log {

    public:
        enum Level {
            LevelError = 0, LevelWarning, LevelInfo
        };
    private:
        Level m_LogLevel = LevelError;
        std::string fileName{ "database.txt" };
        std::string output;
        std::vector<std::string>logBuffer;
        bool fileFlag = true;
    public:
        int i = 0;
        Log(Level l1) :m_LogLevel{ l1 }{ };
        ~Log(){ printBuffer(); };
        void SetLogLevel(Level level) {
            this->m_LogLevel = level;
        }
        std::string getCurrentDateTime() {
            auto now = std::chrono::system_clock::now();
            std::time_t time = std::chrono::system_clock::to_time_t(now);
            std::tm tmLocal;
            localtime_s(&tmLocal, &time);
            char buffer[20];
            std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &tmLocal);
            return std::string(buffer);
        }
        template<typename... Args>
        void Warn(const std::string& message,Args... args) {
            if (m_LogLevel >= LevelWarning) {
                std::cout << getCurrentDateTime();
                output = getCurrentDateTime();
                output.append(" [Warning] ").append(message);
                std::cout << " [Warning]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template< typename... Args>
        void Error(const std::string& message, Args... args) {
            if (m_LogLevel >= LevelError) {
                std::cout << getCurrentDateTime();
                output = getCurrentDateTime();
                output.append(" [Error] ").append(message);
                std::cout << " [Error]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        template<typename... Args>
        void Info(const std::string& message,Args... args) {
            if (m_LogLevel >= LevelInfo) {
                std::cout << getCurrentDateTime();
                output = getCurrentDateTime();
                output.append(" [Info] ").append(message).append(" ");
                std::cout << " [Info]: " << message;
                std::cout << " ";
                print(args...);
                std::cout << std::endl;
            }
        }
        /* //Alternative for below five function
        template <typename T>
        std::string toString(const T& value) {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }*/
        std::string toString(const char* value) {
            return std::string(value);
        }
 
        std::string toString(std::string& value) {
            return value;
        }
        std::string toString(int& val) {
            return std::string(std::to_string(val));
        }
        std::string toString(double& val) {
            return std::string(std::to_string(val));
        }
        std::string toString(char& val) {
            return std::string(1, val);
        }
        template <typename T, typename... Types>
        void print(T var1, Types... var2)
        {
            std::cout << var1 << " ";
            std::string temp = toString(var1);
            output = output.append(temp).append(" ");
            print(var2...);
        }
        void print()
        {
           // std::cout << "Last call for print function\n";
            logBuffer.emplace_back(output);
            output.erase(output.begin(), output.end());
            if (logBuffer.size() == 5) {
                printBuffer();
                
            }
        }
        int printBuffer() {
            if (fileFlag) {
                std::ofstream of;
                std::fstream f;
                of.open(fileName, std::ios::app);
                // If we couldn't open the output file stream for writing 
                if (!of)
                {
                    // Print an error and exit 
                    std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
                    return 1;

                }

                // We'll write Cache into this file 
                for (int i = 0; i < logBuffer.size(); i++) {

                    of << logBuffer[i];
                    of << '\n';
                }
                logBuffer.erase(logBuffer.begin(), logBuffer.end());
                of.close();
                return 0;
            }
        }
    };
}
#endif

