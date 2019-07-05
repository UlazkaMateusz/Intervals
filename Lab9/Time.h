#pragma once
#include <string>
class Time
{
private:
	int secound, minute, hour;
	Time();
public:
	Time(int hour, int minute, int secound);
	bool Before(const Time &t) const;
	bool After(const Time &t) const;
	bool Exact(const Time &t) const;

	~Time();

	friend std::ostream& operator<< (std::ostream& stream, const Time& t);
};


