#pragma once
#include <vector>
#include "Interval.h"

class FilesManager
{
private:
	std::vector<Interval*> ram;
	void FreeRam();
	void AddInterval(Interval *i);
	void PrintIntervals() const;
public:
	void LoadInterval(Interval *i);
	void LoadFromString(std::string *str);

	FilesManager();
	~FilesManager();
};

