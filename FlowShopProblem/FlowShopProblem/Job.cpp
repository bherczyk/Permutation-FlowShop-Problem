#include "stdafx.h"
#include "Job.h"

using std::cin;
using std::cout;

Job::Job(const int jobNumber, const int numberOfMachines)
{
	this->jobNumber = jobNumber;
	this->numberOfMachines = numberOfMachines;
	addedJobTimes = 0;
}


Job::~Job()
{
}

bool Job::initData()
{
	cout << "Zadanie numer: " << jobNumber << "\n";
	for (int i = 1; i <= numberOfMachines; i++)
	{
		cout << "Podaj czas pracy na maszynie: " << i << "\n";
		int time = getAndValidateData();
		jobTimeOnMachines.push_back(time);
	}
	addJobTime();
	return true;
}

bool Job::initData(std::fstream& file)
{
	for (int i = 1; i <= numberOfMachines; i++)
	{
		int time = 0;
		file >> time;
		jobTimeOnMachines.push_back(time);
	}
	addJobTime();
	return true;
}

int Job::getAndValidateData()
{
	int number;
	while (!(cin >> number)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Prosze podac liczbe\n";
	}

	return number;
}

void Job::showData() const
{
	cout << "\nZadanie numer: " << jobNumber << "\n";
	cout << "Czas pracy na maszynach: \n";
	for (auto it = jobTimeOnMachines.begin(); it != jobTimeOnMachines.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << "\n";
}

int Job::getTimeJob(const int machineNumber) const
{
	return jobTimeOnMachines.at(machineNumber);
}

int Job::getJobNumber() const
{
	return jobNumber;
}

void Job::addJobTime()
{
	int sum = 0;
	for (auto it = jobTimeOnMachines.begin(); it != jobTimeOnMachines.end(); it++)
	{
		sum += *it;
	}
	addedJobTimes = sum;
}

bool Job::operator < (const Job& other) const
{
	return addedJobTimes < other.addedJobTimes;
}