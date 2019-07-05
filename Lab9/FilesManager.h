#pragma once
#include <vector>
#include "Interval.h"

class FilesManager
{
private:
	std::vector<Interval> ram;
	void FreeRam();
	void AddInterval(Interval &i);
	void PrintIntervals() const;
	std::vector<Interval> GetAllOverlaping(Interval i);
public:
	void LoadInterval(Interval &i);
	void LoadFromString(std::string &str);

	FilesManager();
	~FilesManager();
};

int GetContaingIndex(std::vector<Interval*> overlaping, Interval i);