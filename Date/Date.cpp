#include "Date.h"
int Date::GetYearDay(int year)
{
	if ((year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0))
		return 366;
	return 365;
}
int Date::GetMonthDay(int year, int month)
{
	static const int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((month == 2) && (year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0))
	{
		return 29;
	}

	return monthDay[month];
}

Date::Date(int year, int month, int day)
{
	if (year >= 0
		&& month > 0 && month < 13
		&& day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		//assert(false);
		std::cout << "Date Invalid" << std::endl;
	}
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

// d1 + 100
Date Date::operator+(int day)
{
	Date ret(*this);
	ret._day += day;

	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month >= 13)
		{
			ret._month = 1;
			ret._year++;
		}
	}

	return ret;
}
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year,_month))
	{

		_day -= GetMonthDay(_year,_month);
		_month++;
		if (_month >= 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date ret(*this);
	ret._day -= day;

	while (ret._day < 1)
	{
		ret._month--;
		ret._day += GetMonthDay(ret._year, ret._month);
		if (ret._month < 1)
		{
			ret._month = 12;
			ret._year--;
		}
	}

	return ret;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 1)
	{
		_month--;
		_day += GetMonthDay(_year, _month);
		
		if (_month < 1)
		{
			_month = 12;
			_year--;
		}
	}
	return *this;
}
int Date::operator-(const Date& d)
{
	if ((*this)<d)return -((Date)d-(*this));
	else if (*this == d)return 0;
	int ret = 0;
	int year = d._year;
	int k = 0;
	while (_year-k>year)
	{
		ret += GetYearDay(_year-k);
		k++;
	}
	int month = d._month;
	int i = 0;
	while (_month+i != month)
	{
		
		if (_month > month)
		{
			ret += GetMonthDay(_year, month++);
		}
		else
		{
			ret -= GetMonthDay(_year, _month + i);
			i++;
		}
	}
	ret += _day - d._day;
	if (ret)
		return ret;
	else
		perror("A bug happened at Date count:");
}
Date Date::operator++() // ++d => d.operator++(&d)
{
	return (*this += 1);
}
Date Date::operator++(int) // d++ => d.operator(&d, 0);
{
	Date ret(*this);
	*this += 1;
	return ret;
}
Date Date::operator--() // --d 
{
	return (*this -= 1);
}
Date Date::operator--(int) // d--
{
	Date ret(*this);
	*this -= 1;
	return ret;
}
int main()
{
	Date d1(2015, 12, 31);
	Date d2(2020, 1, 1);
	std::cout << d2 - d1 << std::endl;
	std::cout << 365*4+2 << std::endl;
	d2 = d1++;
	d1.display();
	d2.display();
	d2 -= 100;
	d2.display();
	d1 = d2 + 100;
	d1.display();
	system("pause");
	return 0;
}