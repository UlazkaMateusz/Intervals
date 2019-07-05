#include "pch.h"
#include "DateTime.h"
#include <iostream>

DateTime::DateTime() {}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int secound)
{
	date = std::make_shared<Date>(Date(year, month, day));
	time = std::make_shared<Time>(Time(hour, minute, secound));
}

DateTime::DateTime(DateTime& dt)
{
	date = std::make_shared<Date>(*dt.date);
	time = std::make_shared<Time>(*dt.time);
}


bool DateTime::After(const DateTime &dt) const
{
	if (date->After(*(dt.date)))
		return true;
	else if (date->Exact(*(dt.date)) && time->After(*(dt.time)))
		return true;
	
	return false;
}

bool DateTime::Before(const DateTime &dt) const
{
	if (date->Before(*(dt.date)))
		return true;
	else if (date->Exact(*(dt.date)) && (time->Before(*(dt.time))))
		return true;
	else
		return false;
}

bool DateTime::Exact(const DateTime &dt) const
{
	if (date->Exact(*(dt.date)) && time->Exact(*(dt.time)))
		return true;
	else
		return false;
}


DateTime::~DateTime()
{
}


std::ostream & operator<<(std::ostream & stream, const DateTime &dt)
{
	stream << *(dt.date) << " " << *(dt.time);
	return stream;
}
