#include "Date.h"
#include<iostream>
using namespace std;

int Date::DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

void Date::IsCorrectDatePlus()
{
	LeapYear(year);	
	if (day> DaysInMonth[month - 1]) {
		day-= DaysInMonth[month - 1];
		month++;
	}
	if (month > 12) {
		month-=12;
		year+=1+month/12;
	}
	if (year > 9999) {
		year = 1;
	}		
	
	if (DaysInMonth[1] == 29)
		DaysInMonth[1] = 28;	
}

void Date::IsCorrectDateMinus()
{
	LeapYear(year);
	if (day < 1) {
		month--;
		day = DaysInMonth[month - 1];
	}
	if (month < 1) {
		month = 12;
		year--;
		day = DaysInMonth[month - 1];
	}
	if (year < 1) {
		year = 1;
		day = 1;
		month = 1;
	}

	if (DaysInMonth[1] == 29)
		DaysInMonth[1] = 28;

}

int Date::GetDay()
{
	return day;
}

void Date::SetDay(int day)
{
	this->day = day;
}

Date& Date::operator+=(const int& num)
{
	Date res(day += num, month, year);
	IsCorrectDatePlus();
	return res;
}

Date& Date::operator-=(const int& num)
{
	Date res(day -= num, month, year);
	IsCorrectDateMinus();
	return res;
}

void Date::operator()(int days)
{
	day += days;
	IsCorrectDatePlus();
}

void Date::operator()(int days, int months)
{
	day += days;
	month += months;
	IsCorrectDatePlus();
}

void Date::operator()(int days, int months, int years)
{
	day += days;
	month += months;
	year += years;
	IsCorrectDatePlus();
}

ofstream& operator<<(ofstream& out, Date & date)
{
	out << date.day << endl;
	out << date.month << endl;
	out << date.year << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Date& date)
{
	in >> date.day;
	in >> date.month;
	in >> date.year;

	return in;
	
}



Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
}

Date::Date(int day, int month, int year) 
{
	LeapYear(year);		
	if (year >= 0 && year <= 9999 &&
		month > 0 && month <= 12 &&
		day > 0 && day <= DaysInMonth[month - 1])
	{
		this->day = day;
		this->month = month;
		this->year = year;

		if (DaysInMonth[1] == 29)
			DaysInMonth[1] = 28;
	}
	else {
		this->day = 1;
		this->month = 1;
		this->year = 1;
	}
}

void Date::Print() const
{
	cout << "Date: " << day << "."
		<< month << "." << year << endl;
}



void Date::PlusOneDay()
{
	day++;
	IsCorrectDatePlus();

}

void  Date::LeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		DaysInMonth[1] = 29;		
	}	
}


bool operator>(const Date& d1, const Date& d2)
{
	return  (d1.year > d2.year ||
		d1.year == d2.year &&
		d1.month > d2.month ||
		d1.year == d2.year &&
		d1.month == d2.month &&
		d1.day > d2.day);
}

bool operator<(const Date& d1, const Date& d2)
{
	return  (d1.year < d2.year ||
		d1.year == d2.year &&
		d1.month < d2.month ||
		d1.year == d2.year &&
		d1.month == d2.month &&
		d1.day < d2.day);
}

bool operator==(const Date& d1, const Date& d2)
{
	return  (d1.year == d2.year &&
		d1.month == d2.month  &&
		d1.day == d2.day);
}

bool operator!=(const Date& d1, const Date& d2)
{
	return  (d1.year != d2.year ||
		d1.month != d2.month ||
		d1.day != d2.day);
}

Date operator++(Date &d)
{
	int day = d.GetDay();	
	d.SetDay(++day);
	d.IsCorrectDatePlus();
	return d;
}

Date operator++(Date& d,int k)
{
	Date temp = d;
	int day = d.GetDay();
	day++;
	d.SetDay(day);
	d.IsCorrectDatePlus();
	return temp;
}

Date operator--(Date& d)
{
	int day = d.GetDay();
	d.SetDay(--day);
	d.IsCorrectDateMinus(); 
	return d;
}

Date operator--(Date& d, int k)
{
	Date temp = d;
	int day = d.GetDay();
	day--;
	d.SetDay(day);
	d.IsCorrectDateMinus();
	return temp;
}

