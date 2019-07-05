#include "pch.h"
#include "Date.h"
#include <sstream>
#include <iostream>

Date::Date() {}


Date::Date(int year, int month, int day)
{
	// Check year, month and day
	if ((year >= 1900 && year <= 3000) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else
	{
		std::stringstream ss;
		ss << "Cannot create Date object with year:" << year << " month: " << month << " day: " << day;
		throw ss.str();
	}
}

bool Date::After(const Date &d) const
{
	if (year > d.year)
		return true;
	else if (year < d.year)
		return false;

	if (month > d.month)
		return true;
	else if (month < d.month)
		return false;

	if (day > d.day)
		return true;
	else
		return false;
}

bool Date::Before(const Date &d) const
{
	if (year < d.year)
		return true;
	else if (year > d.year)
		return false;

	if (month < d.month)
		return true;
	else if (month > d.month)
		return false;

	if (day < d.day)
		return true;
	else
		return false;
}

bool Date::Exact(const Date &d) const
{
	if (year == d.year && month == d.month && day == d.day)
		return true;
	return false;
}


Date::~Date()
{
}


std::ostream & operator<<(std::ostream & stream, const Date & d)
{
	stream << d.year << "." << d.month << "." << d.day;
	return stream;
}
