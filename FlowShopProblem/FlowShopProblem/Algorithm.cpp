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

void Algorithm::showResult() const
{
	cout << "\nCmax = " << makespan;
	cout << "\nKolejnosc = ";
	for (auto it = resultSchedule.begin(); it != resultSchedule.end(); it++)
	{
		cout << it->getJobNumber() << " , ";
	}
}


int Algorithm::computeMakespan(const int numberOfJobsInResultSchedule)
{
	std::vector<std::vector<int>> completeTaskTime(numberOfJobsInResultSchedule, std::vector<int>(numberOfMachines));
	for (int i = 0; i < numberOfJobsInResultSchedule; i++)
	{
		for (int j = 0; j < numberOfMachines; j++)
		{
			
			int first = i > 0 ? completeTaskTime[i - 1][j] : 0;
			int second = j > 0 ? completeTaskTime[i][j - 1] : 0;

			int greaterTaskTime = max(first, second);
			completeTaskTime[i][j] = greaterTaskTime + resultSchedule[i].getTimeJob(j);
			
		}
	}
	return completeTaskTime.back().back();
}

int Algorithm::max(const int first, const int second)
{
	return first > second ? first : second;
}

