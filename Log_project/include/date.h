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
			bool isFirstCallDone = false;
		};
		int day, month, year;
		mutable bool isCacheValid = false;
		String cache;
		previousDay prev;
	public:
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
		int daysInMonth(const int m);
		void getCache();
		void operator=(const Date& newDate);
	};
}
#endif

