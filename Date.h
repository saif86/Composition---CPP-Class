#ifndef DATE_H_
#define DATE_H_
#include <iostream>

using namespace std;
class Date
{
	int day;
	int month;
	int year;
	static Date defaultDate;	// class variable shared by all objects of date class
	int checkDay(int) const;	// utility function to confirm proper day value based on month and year
	bool leapyear(int)const;	// utility function to check leap years
public:
	Date(int = 0, int = 0, int = 0);	// Constructor
	Date(const Date &);			// Copy Constructor

	friend ostream & operator <<(ostream &, const Date &);		// Stream Insertion
	friend istream & operator >>(istream &, Date &);			// Stream Extraction

	// setters
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int = 0, int = 0, int = 0);
	void setDate(const Date &);

	// getters
	int getDay()const;
	int getMonth()const;
	int getYear()const;

	void addDay(int);
	void addMonth(int);
	void addYear(int);

	static void setDefaultDate(int = 0, int = 0, int = 0);		// default date setter function
	static const Date & getDefaultDate();						// defualt date getter function
};
#endif