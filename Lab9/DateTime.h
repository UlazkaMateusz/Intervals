#pragma once
#include "Date.h"
#include "Time.h"
#include <string>
#include <memory>

class DateTime
{
private:
	std::shared_ptr<Date> date;
	std::shared_ptr<Time> time;

	DateTime();
public:
	DateTime(int year, int month, int day, int hour, int minute, int secound);
	DateTime(DateTime& dt);
	bool Before(const DateTime &dt) const;
	bool After(const DateTime &dt) const;
	bool Exact(const DateTime &dt) const;

	~DateTime();

	friend std::ostream& operator<<(std::ostream& stream, const DateTime& dt);
};

