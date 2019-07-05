#include "pch.h"
#include "Time.h"
#include <sstream>

Time::Time() {}

Time::Time(int hour, int minute, int secound)
{
	// Check if hour, minute and secound are valid
	if ((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60) && (secound >= 0 && secound < 60))
	{
		this->hour = hour;
		this->minute = minute;
		this->secound = secound;
	}
	else
	{
		// If hour, minute or secound are not valid throw exceptions
		std::stringstream ss;
		ss << "Cannot create Time object with hour:" << hour << " minute: " << minute << " secound: " << secound;
		throw ss.str();
	}
}

bool Time::Before(const Time &t) const
{
	// Check if this object is before time t

	// Compare hours
	if (hour < t.hour)
		return true;
	else if (hour > t.hour)
		return false;

	// Compare minutes
	if (minute < t.minute)
		return true;
	else if (minute < t.minute)
		return false;

	// Compare secounds
	if (secound < t.secound)
		return true;
	else
		return false;
}

bool Time::After(const Time &t) const
{
	// Check if this object is before time t

	// Compare hours
	if (hour > t.hour)
		return true;
	else if (hour < t.hour)
		return false;

	// Compare minutes
	if (minute > t.minute)
		return true;
	else if (minute < t.minute)
		return false;

	// Compare secounds
	if (secound > t.secound)
		return true;
	else
		return false;
}

bool Time::Exact(const Time &t) const
{
	if ((hour == t.hour) && (minute == t.minute) && (secound == t.secound))
		return true;

	return false;
}

Time::~Time()
{
}

std::ostream & operator<<(std::ostream & stream, const Time & t)
{
	stream << t.hour << ":" << t.minute << ":" << t.secound;
	return stream;
}