#include "stdafx.h"
#include "Algorithm.h"

using std::cout;
using std::cin;

Algorithm::Algorithm()
{
	int numberOfMachines = 0;
	int numberOfJobs = 0;
	int makespan = 0;
}


Algorithm::~Algorithm()
{
}


bool Algorithm::initData() 
{
	cout << "Podaj liczbe zadan\n";
	numberOfJobs = getAndValidateData();
	
	cout << "Podaj liczbe maszyn \n";
	numberOfMachines = getAndValidateData();

	for (int i = 1; i <= numberOfJobs; i++)
	{
		Job p(i,numberOfMachines);
		p.initData();
		jobs.push_back(p);
	}

	return true;
}

int Algorithm::getAndValidateData()
{
	int number;
	while (!(cin >> number)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Prosze podac liczbe\n";
	}

	return number;
}



bool Algorithm::initData(const std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	if (file.good())
	{
		file >> numberOfJobs;
		file >> numberOfMachines;
		for (int i = 1; i <= numberOfJobs; i++)
		{
			Job p(i, numberOfMachines);
			p.initData(file);
			jobs.push_back(p);
		}
	}
	else
	{
		return false;
	}
	file.close();
	return true;
}



void Algorithm::showData() const
{
	cout << "\nLiczba zadan: " << numberOfJobs << " , Liczba maszyn: " << numberOfMachines << "\n";
	
	for (auto it = jobs.begin(); it != jobs.end(); it++)
	{
		it->showData();
	}
}


