#include <iostream>
#include "..\include\date.h"
#include "..\include\string.h"
using namespace utility;

// Date Class implementation of all function definations



void Date::dateToString() {

	cache.flush();
	String day = utility::String::intToString(Date::day);
	String month = utility::String::intToString(Date::month);
	String year = utility::String::intToString(Date::year);
	
	cache + day + "/" + month + "/" + year;
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

