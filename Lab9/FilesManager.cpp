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
		ram[i].IncremetAge();

		if (ram[i].getAge() >= 15)
		{
			std::cout << "Deleting: " << ram[i] << std::endl;
			ram.erase(ram.begin() + i);
		}
	}
}

void FilesManager::AddInterval(Interval &i)
{

	for (int j = 0; j < ram.size(); j++)
	{
		if (i.StartsBefore(ram[j]))
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
		std::cout << ram[i] << std::endl;
	}
	std::cout << std::endl;
}

std::vector<Interval> FilesManager::GetAllOverlaping(Interval i)
{
	std::vector<Interval> overlaping;

	for (int j = 0; j < ram.size(); j++)
		if (ram[j].Overlaps(i) || i.Contains(ram[j]))
			overlaping.push_back(ram[j]);

	return overlaping;
}

void FilesManager::LoadInterval(Interval &i)
{
	std::vector<Interval> overlaping = GetAllOverlaping(i);	

	for (int j = 0; j < overlaping.size(); j++)
	{
		if (overlaping[j].Contains(i))
		{
			std::cout << "Reading from RAM: " << overlaping[j] << std::endl;
			FreeRam();
			PrintIntervals();
			return;
		}
		
		if (j + 1 < overlaping.size())
			if (!overlaping[j].getEnd().Exact(overlaping[j + 1].getStart()))
			{
				DateTime start(overlaping[j].getEnd());
				DateTime end(overlaping[j + 1].getStart());
				Interval interval(start, end);
				std::cout << "Reading from Disk: " << interval << std::endl;
				AddInterval(interval);
			}
	}

	if (!overlaping.empty())
	{
		if (i.StartsBefore(overlaping[0]))
		{
			DateTime start(i.getStart());
			DateTime end(ram[0].getStart());
			Interval interval(start, end);
			std::cout << "Reading from Disk: " << interval << std::endl;
			AddInterval(interval);
		}

		if (i.EndsAfter(overlaping[overlaping.size() - 1]))
		{
			DateTime start(overlaping[overlaping.size() - 1].getEnd());
			DateTime end(i.getEnd());
			Interval interval(start, end);
			std::cout << "Reading from Disk: " << interval << std::endl;
			AddInterval(interval);
		}
	}
	
	if (ram.empty() || overlaping.empty())
	{
		std::cout << "Reading from Disk: " << i << std::endl;
		AddInterval(i);
	}

	for (int j = 0; j < overlaping.size(); j++)
		std::cout << "Reading from RAM: " << overlaping[j] << std::endl;

	FreeRam();
	PrintIntervals();
}

void FilesManager::LoadFromString(std::string &str)
{
	std::stringstream ss;

	ss << str;

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

	DateTime dt1(year, month, day, hour, minute, secound);
	
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
	DateTime dt2(year, month, day, hour, minute, secound);
	Interval interval(dt1, dt2);
	LoadInterval(interval);

}

FilesManager::~FilesManager()
{
	ram.clear();
}
