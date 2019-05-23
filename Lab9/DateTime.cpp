#include "pch.h"
#include "DateTime.h"

DateTime::DateTime() {}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int secound)
{
	date = new Date(year, month, day);
	time = new Time(hour, minute, secound);
}

DateTime::DateTime(const DateTime *dt)
{
	date = new Date(dt->date);
	time = new Time(dt->time);
}

bool DateTime::After(const DateTime *dt) const
{
	if (date->After(dt->date))
		return true;
	else if (date->Exact(dt->date) && time->After(dt->time))
		return true;
	
	return false;
}

bool DateTime::Before(const DateTime *dt) const
{
	if (date->Before(dt->date))
		return true;
	else if (date->Exact(dt->date) && (time->Before(dt->time)))
		return true;
	else
		return false;
}

bool DateTime::Exact(const DateTime *dt) const
{
	if (date->Exact(dt->date) && time->Exact(dt->time))
		return true;
	else
		return false;
}


DateTime::~DateTime()
{
	delete time;
	delete date;
}

bool DateTime::operator==(const DateTime *dt) const
{
	if ((date == dt->date) && (time == dt->time))
		return true;

	return false;
}

bool DateTime::operator!=(const DateTime *dt) const
{
	return !(*this == dt);
}

std::ostream & operator<<(std::ostream & stream, const DateTime &dt)
{
	stream << *(dt.date) << " " << *(dt.time);
	return stream;
}
