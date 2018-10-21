#pragma once
#include<iostream>
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);

	// Date(const Date& d);
	// Date& operator=(const Date& d);
	// ~Date();
	void display()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date operator++(); // ++d => d.operator++(&d)
	Date operator++(int); // d++ => d.operator(&d, 0);
	Date operator--(); // --d 
	Date operator--(int); // d--

	int GetYearDay(int year);
	int GetMonthDay(int year, int month);
private:
	int _year;
	int _month;
	int _day;
};