#include<iostream>

#include "include\log.h" 
#include "include\date.h"
#include "include\string.h"
#include"include\exception.h"
using namespace logging;
using namespace utility;


int main() {
  
    Date d2{ 3,1,2024 };
    Log log{ Log::LevelWarning , d2};
    log.SetLogLevel(Log::LevelInfo);
    log.Info("Fine ! ");
    log.Warn("Careful ! ");
   
    log.Error("Stop ! ");
    log.changeDate(Date{ 5,1,2024 });
    log.Info("New Fine ");
    log.changeDate(Date{ 5,1,2024 });
    log.Info("New Fine ");
   
    return 0;
}

