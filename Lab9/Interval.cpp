#include "pch.h"
#include "Interval.h"


Interval::Interval() {}

Interval::Interval(const DateTime* s, const DateTime* e)
{
	if (!s->Before(e))
		throw "Cannot create Interval if end is before start";

	start = new DateTime(s);
	end = new DateTime(e);
	age = 0;
}

Interval::Interval(const Interval *i)
{
	start = new DateTime(i->start);
	end = new DateTime(i->end);
	age = 0;
}

Interval::Interval(DateTime s, DateTime e)
{
	start = new DateTime(s);
	end = new DateTime(e);
	age = 0;
}

const DateTime* Interval::getStart() const
{
	return start;
}

const DateTime* Interval::getEnd() const
{
	return end;
}

int Interval::getAge() const
{
	return age;
}

void Interval::IncremetAge()
{
	age++;
}

bool Interval::Contains(const DateTime *i) const
{
	if ((start->Before(i) || start->Exact(i))  && (end->After(i) || end->Exact(i)))
		return true;
	
	return false;
}

bool Interval::Contains(const Interval *i) const
{
	if (((start->Before(i->start)) || start->Exact(i->start)) && ((end->After(i->end)) || end->Exact(i->end)))
		return true;

	return false;
}

bool Interval::Overlaps(const Interval *i) const
{
	if (Contains(i->getStart()) || Contains(i->getEnd()))
		return true;
	
	return false;
}

bool Interval::StartsBefore(const Interval *i) const
{
	if (start->Before(i->getStart()))
		return true;
	else
		return false;
}

bool Interval::EndsAfter(const Interval *i) const
{
	if (end->After(i->getEnd()))
		return true;
	else
		return false;
}

Interval::~Interval()
{
	delete start;
	delete end;
}

std::ostream & operator<<(std::ostream & stream, const Interval & i)
{
	stream << *(i.start) << " - " << *(i.end);
	return stream;
}
