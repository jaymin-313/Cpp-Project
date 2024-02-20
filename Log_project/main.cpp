#include<iostream>
#include<string>
#include "include\log.h" 
#include "include\date.h"
#include "include\string.h"
#include"include\exception.h"
using namespace logging;
using namespace utility;


int main() {
  
    
    Log log{ Log::LevelWarning};
    log.SetLogLevel(Log::LevelInfo);

    log.Info("Fine ! ",23 , 3.23232);
    log.Warn("Careful ! ", 1, 2.3);
    std::string s1 = "New String";
    log.Error("Stop ! ",23,4.3445,'B',s1,"Const char String");
   //log.changeDate(Date{ 5,1,2024 });
    log.Info("New Fine ");
   // log.changeDate(Date{ 5,1,2024 });
    log.Info("New Fine ");
    log.Error("Crashing");
    
    return 0;
}

