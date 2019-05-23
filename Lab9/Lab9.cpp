// Lab9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include "FilesManager.h"
#include "Interval.h"
#include <sstream>
#include <fstream>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FilesManager *manager =  new FilesManager();

	try
	{
		std::string interval;


		// Some readings from string
		std::string inter[] = { "2014.2.6 7:17 : 51 - 2025.9.21 4 : 58 : 14" ,
								"2012.12.28 10:44:4 - 2013.12.23 7:15:43" ,
								"2020.3.18 23:25:43 - 2034.3.28 23:19:49" ,
								"2015.6.6 1:0:5 - 2029.7.7 17:32:45" ,
								"2007.11.6 17:45:50 - 2047.12.27 12:2:19" ,
								"2008.11.9 12:31:25 - 2047.8.11 12:14:48" ,
								"2005.9.15 7:49 : 25 - 2040.3.21 10 : 31 : 45",
								"2007.11.1 18:44:4 - 2017.3.20 15:17:13" };

		for (int i = 0; i < 8; i++)
		{
			std::cout << "Type Interval to read: " + inter[i] + "\n";
			manager->LoadFromString(&inter[i]);
		}


		/*while (true)
		{
			std::cout << "Type Interval to read: ";
			std::getline(std::cin, interval);
			manager->LoadFromString(interval);
			std::cout << std::endl;
		}*/
	}
	catch (std::string &error)
	{
		std::cerr << std::endl << error << std::endl;
	}

	delete manager;
}
