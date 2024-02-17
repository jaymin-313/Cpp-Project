#include"string.h"
#include"exception.h"
#ifndef DATE_H
#define DATE_H
using namespace utility;
namespace utility {

	class Date {
	private:
		struct previousDay {
			int pre_d, pre_month, pre_year;
			bool isFirstCall = true;
		};
		int day, month, year;
		mutable bool cache_valid = false;
		String cache;
		String date;
		previousDay prev;
		void compute_cache_value() {
			if (!cache_valid) {
				 dateToString();
				//cache = std::move(date);
				 cache_valid = true;
				// std::cout << "sourabh\n";
			}
		}

	public:
		Date(int d=1, int m=1, int y=2024) {

			day = d;
			month = m;
			year = y;
			try {
				if (!dateValid() ){
					throw myException("Invalid Date");
					
				}
			}
			catch (const myException& e) {
				
				std::cout<<"Caught MyException: "<< e.what();
				
			}
			if (prev.isFirstCall || isDateUpdated()) {
				prev.pre_d = day;
				prev.pre_month = month;
				prev.pre_year = year;
				compute_cache_value();
				//getCache();
				prev.isFirstCall = false;
			}

			//compute_cache_value();
			//dateToString();
			/*stringRep();
			compute_cache_value();*/
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

		bool isDateUpdated() {
			return ((prev.pre_d == day) && (prev.pre_month == month) && (prev.pre_year == year)) ? false : true;
		}
		bool isLeap(int year) {
			
				if (year % 4 == 0) {
					if (year % 100 == 0) {
						if (year % 400 == 0) {
							return true;
						}
						else {
							return false;
						}
					}
					else {
						return true;
					}
				}
				else {
					return false;
				}
		}
		
		void dateToString();
		void addDays(const int d);
		void addMonths(const int m);
		void addYears(const int y);
		//void updateCache(Date& d);
		int daysInMonth(const int m);
		//void getUpdatedDate() const;
		//void intToString(int a);
		//char* stringRep();
		//void updateCache(Date& d1);
		void  getCache() ;
		//int reverseDigits(int num);
	};
}
#endif

