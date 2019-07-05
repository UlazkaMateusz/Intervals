#pragma once
#include <string>
class Date
{
private:
	int day, month, year;
	Date();
public:
	Date(int year, int month, int day);
	bool Before(const Date &d) const;
	bool After(const Date &d) const;
	bool Exact(const Date &d) const;

	~Date();

	friend std::ostream& operator<<(std::ostream& stream, const Date& d);
};

