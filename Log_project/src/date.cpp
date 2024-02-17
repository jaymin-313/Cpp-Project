#include <iostream>
#include "..\include\date.h"
#include "..\include\string.h"
using namespace utility;

// Date Class implementation of all function definations



void Date::dateToString() {
	//String s1 = utility::String::intToString(Date::day);
	//String s2 = utility::String::intToString(Date::month);
	//String s3 = utility::String::intToString(Date::year);
	////String s4 = s1 + '/' + s2 + "/" + s3;
	//s1.concatenate("/");
	//s1.concatenate(s2);
	//s1.concatenate("/");
	//s1.concatenate(s3);
	////s1.concatenate("0");
	//cache = std::move( s1);
	std::cout << "sourabh\n";
	cache.flush();
	cache.concatenate(utility::String::intToString(Date::day));
	cache.concatenate("/");
	cache.concatenate(utility::String::intToString(Date::month));
	cache.concatenate("/");
	cache.concatenate(utility::String::intToString(Date::year));
	
	
}

String Date::getCache() {
	if (!isCacheValid)
	{
		dateToString();
		isCacheValid = true;
	}
	return cache;
}

bool isLeap(int year) {

	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	return (year % 4 == 0);

}

void Date::addDays(const int d) {

	day += d;

	while (day > daysInMonth(month)) {
		day -= daysInMonth(month);
		addMonths(1);
	}
	//dateToString();
}

void Date::addMonths(const int m)
{
	if ((m + month) <= 12)
		month += m;
	else {
		month += m;
		year += (month / 12);
		month = (month % 12);
	}
	//dateToString();
}
void Date::addYears(const int y)
{
	year += y;
	//dateToString();
}

//void Date::setCache(){
//	std::cout << cache;
//
//	if (!isCacheValid)
//	{
//		dateToString();
//		isCacheValid = true;
//	}
//	
//	std::cout << cache;
//}

int Date::daysInMonth(const int month) {
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		//return isLeapYearFlag ? 29 : 28;
		return 28;
	default:
		return 31;
	};
}
//void Date::updateCache(Date& d1) {
//	d1.dateToString();
//	
//	utility::Date::cache = std::move(d1.date);
//}
//void Date::getUpdatedDate() const
//{
//	std::cout << " Modified Date : ";
//	int i = 0;
//	while (date[i] != '\0') {
//		std::cout << date[i];
//		++i;
//	}
//	std::cout << "\n";
//}

//void Date::updateCache(Date& d) {
//	if(d.date ==  )
//}

void Date::operator=(const Date& newDate) {
	if (isDateUpdated(newDate)) {
		this->day = newDate.day;
		this->month= newDate.month;
		this->year = newDate.year;
		this->prev = newDate.prev;
		prev.isFirstCallDone = true;
		isCacheValid = false;

	}
}

