#include"string.h"
#include"exception.h"
#ifndef DATE_H
#define DATE_H
#include<fstream>
using namespace utility;
namespace utility {

	class Date {
	private:
		struct previousDay {
			int pre_d, pre_month, pre_year;
			bool isFirstCallDone = false;
		};
		int day, month, year;
		mutable bool isCacheValid = false;
		
		previousDay prev;
		
	public:
		String cache;
		Date(int d=1, int m=1, int y=2024) : day{ d }, month{ m }, year{y} {

			try {
				if (!dateValid() ){
					throw myException("Invalid Date");
					
				}
			}
			catch (const myException& e) {
				
				std::cout<<"Caught MyException: "<< e.what();
				
			}
			if (isDateUpdated(*this)) {
				prev.pre_d = day;
				prev.pre_month = month;
				prev.pre_year = year;
				isCacheValid = false;
				//getCache();
			
			}

		}

		bool dateValid() {
			if (month < 1 || month > 12)
				return false;
			if (day < 1 || day > 31)
				return false;

			if (month == 2)
			{
				if (isLeap(year))
					return (day <= 29);
				else
					return (day <= 28);
			}
			if (month == 4 || month == 6 ||
				month == 9 || month == 11)
				return (day <= 30);

			return true;
		}

		bool isDateUpdated(const Date& d) {
			if (!prev.isFirstCallDone) {
				prev.isFirstCallDone = true;
				return true;
			}
			return ((prev.pre_d == d.day) && (prev.pre_month == d.month) && (prev.pre_year == d.year)) ? false : true;
		}
		bool isLeap(int year) {
			if (year % 400 == 0) return true;
			if (year % 100 == 0) return false;
			return (year % 4 == 0);
		}
		
		void dateToString();
		void addDays(const int d);
		void addMonths(const int m);
		void addYears(const int y);
		int daysInMonth(const int m);
		String getCache();
		//int dumpCache(const char* s) {
		//	std::ofstream of;
		//	std::fstream f;
		//	of.open(s , std::ios::app);
		//	// If we couldn't open the output file stream for writing 
		//	if (!of)
		//	{
		//		// Print an error and exit 
		//		std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
		//		return 1;

		//	}

		//	// We'll write two lines into this file 
		//	//of << '\n';
		//	of << cache;
		//	of.close();
		//	return 0;
		//}
		void operator=(const Date& newDate);
	};
}
#endif

