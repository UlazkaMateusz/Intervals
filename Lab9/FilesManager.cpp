#include "pch.h"
#include "FilesManager.h"
#include <algorithm>
#include <iostream>
#include <sstream>

FilesManager::FilesManager()
{
}

void FilesManager::FreeRam()
{
	for (int i = ram.size()-1; i >= 0; i--)
	{
		ram[i]->IncremetAge();

		if (ram[i]->getAge() >= 15)
			ram.erase(ram.begin() + i);
	}
}

void FilesManager::AddInterval(Interval *i)
{

	for (int j = 0; j < ram.size(); j++)
	{
		if (i->StartsBefore((ram[j])))
		{
			ram.insert(ram.begin() + j, i);
			return;
		}
	}

	ram.push_back(i);
}

void FilesManager::PrintIntervals() const
{
	std::cout << "Intervals in ram:" << std::endl;

	for (int i = 0; i < ram.size(); i++)
	{
		std::cout << *(ram[i]) << std::endl;
	}
	std::cout << std::endl;
}

void FilesManager::LoadInterval(Interval *i)
{
	std::vector<Interval*> ram_load;

	for (int j = 0; j < ram.size(); j++)
		if (ram[j]->Overlaps(i) || i->Contains(ram[j]))
			ram_load.push_back(ram[j]);
	

	for (int j = 0; j < ram_load.size(); j++)
	{
		if (ram_load[j]->Contains(i))
		{
			std::cout << "Reading from RAM: " << *(ram_load[j]) << std::endl;
			FreeRam();
			PrintIntervals();
			delete i;
			return;
		}

		if (j + 1 < ram_load.size())
			if (!ram_load[j]->getEnd()->Exact(ram_load[j + 1]->getStart()))
			{
				Interval* tmp = new Interval(new DateTime(ram_load[j]->getEnd()), new DateTime(ram_load[j + 1]->getStart()));
				std::cout << "Reading from Disk: " << *(tmp) << std::endl;
				AddInterval(tmp);
			}
	}

	if (!ram_load.empty())
	{
		if (i->StartsBefore(ram_load[0]))
		{
			Interval* tmp = new Interval(new DateTime(i->getStart()), new DateTime(ram[0]->getStart()));
			std::cout << "Reading from Disk: " << *(tmp) << std::endl;
			AddInterval(tmp);
		}

		if (i->EndsAfter(ram_load[ram_load.size() - 1]))
		{
			Interval* tmp = new Interval(new DateTime(ram_load[ram_load.size() - 1]->getEnd()), new DateTime(i->getEnd()));
			std::cout << "Reading from Disk: " << *(tmp) << std::endl;
			AddInterval(tmp);
		}
	}
	
	if (ram.empty() || ram_load.empty())
	{
		std::cout << "Reading from Disk: " << *(i) << std::endl;
		AddInterval(i);
		FreeRam();
		PrintIntervals();
		return;
	}

	// Print out Ram
	for (int j = 0; j < ram_load.size(); j++)
		std::cout << "Reading from RAM: " << *(ram_load[j]) << std::endl;

	FreeRam();
	PrintIntervals();

	while (ram_load.size() != 0)
		ram_load.clear();

	delete i;
}

void FilesManager::LoadFromString(std::string *str)
{
	std::stringstream ss;

	ss << *str;

	int year, month, day, hour, minute, secound;
	char w;
	ss >> year
		>> w
		>> month
		>> w
		>> day
		>> hour
		>> w
		>> minute
		>> w
		>> secound;

	DateTime *dt1 = new DateTime(year, month, day, hour, minute, secound);
	
	ss >> w;

	ss >> year 
		>> w 
		>> month
		>> w 
		>> day
		>> hour 
		>> w
		>> minute 
		>> w
		>> secound;
	DateTime *dt2 = new DateTime(year, month, day, hour, minute, secound);

	LoadInterval(new Interval(dt1, dt2));
	delete dt1;
	delete dt2;
}

FilesManager::~FilesManager()
{
	for (int i = 0; i < ram.size(); i++)
		delete ram[i];

	ram.clear();
}
