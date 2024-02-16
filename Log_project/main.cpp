#include<iostream>

#include "include\log.h" 
#include "include\date.h"
#include "include\string.h"
#include"include\exception.h"
using namespace logging;
using namespace utility;


int main() {
    // using namespace d;
    
   // Log log;
    Log log{ Log::LevelWarning,{3,1,2024} };
    log.SetLogLevel(Log::LevelInfo);
    log.Info("Fine !");
    log.Warn("Careful !");
   
    log.Error("Stop !");
    
//    Date d{ 34,15,2024 };

   /* d::date today{ 12, 1, 2024 };
    today.print_date();*/
   //Date d{ 31,1,2024 };
   /* d.addDays(1);
    d.addMonths(2);
    d.addYears(3);*/
   // utility::Date::getCache();
   // d.getCache();
   
   
    //String s = d.stringRep();
   // d.getCache();
    //d.getUpdatedDate();

    //d.stringRep();
      //getCache();
 /* String s1("HELLO EVERYONE");
		String s12(" Welcome to C++ Training");
        String s3 = s1;
        String s4 = "New string";
         s4.concatenate(s12);
         s4.print();*/
       
  /*      s1.tolowercase();
        s1.print();
        s1.touppercase();
        s1.print();
        s1.concatenate(s12);
		s1.print();
        char b = s1[44];
        char c = s1[3];
        std::cout << b << c<< std::endl;*/
  
    std::cin.get();
}

//int main() {
//	////String s;
//	//String s1("HELLO EVERYONE");
//	//String s12(" Welcome to C++ Training ");
//	////s1.print();
//	//s1.tolowercase();
//	//s1.print();
//	//
//	//s1.touppercase();
//	/*s1.concatenate(s12);
//	s1.print();*/
//	//s1.print();
//	////std::cout << s1.length() << std::endl;
//	//s1.getlength();
//	//std::cout << s1 << std::endl;
//	String s1; // Default Constructor
//String s2("HEloo"); // Default Constructor
//	String s3(s2); // Copy Constructor
//	String s4(std::move(s3)); // Move Constructor
//	String s5 = s4; // Copy Constructor
//	String s6;
//	s6 = s2; // copy Assignment 
//	s1 = "Move assignment"; // Move Assignment
//	std::cin.get();
//}