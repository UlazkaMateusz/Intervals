#pragma once
#include "Date.h"
#include "Time.h"
#include <string>

class DateTime
{
private:
	Date* date;
	Time* time;
public:
	DateTime();
	DateTime(const DateTime* dt);
	DateTime(int year, int month, int day, int hour, int minute, int secound);
	bool Before(const DateTime *dt) const;
	bool After(const DateTime *dt) const;
	bool Exact(const DateTime *dt) const;

	~DateTime();

	bool operator==(const DateTime *dt) const;
	bool operator!=(const DateTime *dt) const;
	friend std::ostream& operator<<(std::ostream& stream, const DateTime& dt);
};

