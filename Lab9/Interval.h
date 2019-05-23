#pragma once
#include "DateTime.h"

class Interval
{
private:
	DateTime* start;
	DateTime* end;

	int age;
	Interval();
public:
	Interval(const DateTime *s, const DateTime *e);
	Interval(const Interval *i);
	Interval(DateTime s, DateTime e);

	const DateTime* getStart() const;
	const DateTime* getEnd() const;

	int getAge() const;

	void IncremetAge();
	bool Contains(const DateTime *i) const;
	bool Contains(const Interval *i) const;

	bool Overlaps(const Interval *i) const;
	bool StartsBefore(const Interval *i) const;
	bool EndsAfter(const Interval *i) const;

	~Interval();

	friend std::ostream& operator<<(std::ostream& stream, const Interval& i);
};

