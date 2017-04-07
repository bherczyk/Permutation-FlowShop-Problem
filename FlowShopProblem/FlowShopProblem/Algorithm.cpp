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


void Algorithm::computeMakespan(const int numberOfJobsInResultSchedule)
{
	int numberOfJobsInCompleteTaskTime = numberOfJobsInResultSchedule + 1; 
	int numberOfMachinesInCompleteTaskTime = numberOfMachines + 1;
	std::vector<std::vector<int>> completeTaskTime(numberOfJobsInCompleteTaskTime, std::vector<int>(numberOfMachinesInCompleteTaskTime));

	for (int i = 0; i < numberOfJobsInCompleteTaskTime; i++)
	{
		for (int j = 0; j < numberOfMachinesInCompleteTaskTime; j++)
		{
			if (i == 0 || j == 0)
			{
				completeTaskTime[i][j] = 0;
			}
			else
			{
				int greaterTaskTime = max(completeTaskTime[i - 1][j], completeTaskTime[i][j-1]);
				completeTaskTime[i][j] = greaterTaskTime + jobs[i-1].getTimeJob(j);
			}
		}
	}
	makespan = completeTaskTime[numberOfJobsInCompleteTaskTime-1][numberOfMachinesInCompleteTaskTime-1];
}

int Algorithm::max(int first, int second)
{
	return first > second ? first : second;
}

void Algorithm::tests()
{
	for (auto it = jobs.begin(); it != jobs.end(); it++)
	{
		resultSchedule.push_back(*it);
	}

	computeMakespan(numberOfJobs);
}