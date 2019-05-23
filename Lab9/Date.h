#pragma once
#include <string>
class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(const Date *d);
	Date(int year, int month, int day);
	bool Before(const Date *d) const;
	bool After(const Date *d) const;
	bool Exact(const Date *d) const;

	~Date();

	bool operator==(const Date* d) const;
	friend std::ostream& operator<<(std::ostream& stream, const Date& d);
};

