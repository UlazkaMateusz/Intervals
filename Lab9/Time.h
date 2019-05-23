#pragma once
#include <string>
class Time
{
private:
	int secound, minute, hour;
public:
	Time();
	Time(const Time *t);
	Time(int hour, int minute, int secound);
	bool Before(const Time *t) const;
	bool After(const Time *t) const;
	bool Exact(const Time *t) const;

	~Time();

	bool operator==(const Time *t)  const;
	friend std::ostream& operator<< (std::ostream& stream, const Time& t);
};


