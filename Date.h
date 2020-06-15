#pragma once
#include<iostream>
#include<fstream>
using namespace std;

const string fileName = "Date.txt";

class Date
{
private:
	int day, month, year;

	static int DaysInMonth[12];

	friend bool operator>(const Date& d1,const Date& d2);
	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
	friend bool operator!=(const Date& d1, const Date& d2);

	friend ofstream& operator<<(ofstream& out, Date& date);
	friend ifstream& operator>>(ifstream& in, Date& date);


public:
	Date();

	Date(int day, int month, int year);
	
	void Print() const;

	void PlusOneDay();

	void LeapYear(int year);
	
	void IsCorrectDatePlus();

	void IsCorrectDateMinus();

	int GetDay();

	void SetDay(int day);

	Date& operator+=(const int& num);

	Date& operator-=(const int& num);	

	void operator()(int days);
	

	void operator()(int days, int months);
	

	void operator()(int days, int months, int years);
	
};



Date operator++(Date &d);

Date operator++(Date& d, int k);

Date operator--(Date& d);

Date operator--(Date& d, int k);


