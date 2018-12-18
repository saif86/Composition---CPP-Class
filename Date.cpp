#include "Date.h"
#include <iostream>
#include <ctime>

using namespace std;
Date Date::defaultDate(7, 8, 1986);		// Class variable definition


										// Constructor
Date::Date(int d, int m, int y) :day(d), month(m), year(y)
{
	setDate(d, m, y);
}


// Copy Constructor
Date::Date(const Date & obj)
{
	setDate(obj.day, obj.month, obj.year);
}


// Stream Insertion
ostream & operator<<(ostream & os, const Date & d)
{
	os << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
	return os;
}

// Stream Extraction
istream & operator >>(istream & is, Date & d)
{
	int dd, mm, yy;
	cout << "Enter Day: ";
	is >> dd;
	cout << "Enter Month: ";
	is >> mm;
	cout << "Enter Year: ";
	is >> yy;
	d.setDate(dd, mm, yy);

	return is;
}

void Date::setDay(int d)
{
	day = checkDay(d);      // validate the day
}

void Date::setMonth(int m)
{
	if (m > 0 && m <= 12)
		month = m;
	else
		month = defaultDate.month;

}

void Date::setYear(int y)
{
	if (y > 0 && y <= 3000)
		year = y;
	else
		year = defaultDate.year;
}

void Date::setDate(int d, int m, int y) {
	this->setYear(y);
	this->setMonth(m);
	this->setDay(d);
}

void Date::setDate(const Date &obj) {
	setDate(obj.getDay(), obj.getMonth(), obj.getYear());
}
int Date::getDay()const
{
	return this->day;
}
int Date::getMonth()const
{
	return this->month;
}
int Date::getYear()const
{
	return this->year;
}
Date Date::getDate()const {
	return *this;
}
Date Date::getToDay() {
	time_t currentTime = time(NULL);
	struct tm localTime;

	time(&currentTime);                   // Get the current time
	localtime_s(&localTime, &currentTime);  // Convert the current time to the local time

	int Day1 = localTime.tm_mday;
	int Month1 = localTime.tm_mon + 1;
	int Year1 = localTime.tm_year + 1900;
	Date t(Day1, Month1, Year1);
	return t;
}

void Date::addDay(int x) {
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < x; i++) {
		day++;

		// leap year case
		if (month == 2 && day == 29 && leapyear(year))
			continue;

		// determine whether testDay is valid for specified month
		if (day > daysPerMonth[month]) {
			day = 1;
			addMonth(1);
		}
	}
}

void Date::addMonth(int x) {
	for (int i = 0; i < x; i++) {
		month++;
		if (month > 12) {
			month = 1;
			addYear(1);
		}
	}
}

void Date::addYear(int x) {
	year += x;
	// leap year case
	if (day == 29 && month == 2 && !leapyear(year)) {
		day = 1;
		month = 3;
	}
}

double Date::caclAge() {
	double y = 0.0, m= 0.0, d =0.0;
	y = getToDay().getYear() - this->getYear();
	m = getToDay().getMonth() - this->getMonth();
	d = getToDay().getDay() - this->getDay();

	m = m / 12.0;
	d = d / 365.25;
	y = y + m + d;

	return y;
}

void Date::setDefaultDate(int d, int m, int y)
{
	if (d == 0)
		d = getToDay().getDay();
	if (m == 0)
		m = getToDay().getMonth();
	if (y == 0)
		y = getToDay().getYear();
	defaultDate.setDate(d, m, y);
}


const Date & Date::getDefaultDate()
{
	return defaultDate;
}

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
int Date::checkDay(int testDay) const {
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && leapyear(year))
		return testDay;

	cout << "Day " << testDay << " invalid. Set to default day.\n";

	return defaultDate.day;  // leave object in consistent state if bad value
} // end function checkDay

  // utility function to check leap years
bool Date::leapyear(int y)const {
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		return true;
	else
		return false;
}
