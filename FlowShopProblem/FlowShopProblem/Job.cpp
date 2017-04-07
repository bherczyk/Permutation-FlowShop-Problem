#include "stdafx.h"
#include "Job.h"

using std::cin;
using std::cout;

Job::Job(int jobNumber, int numberOfMachines)
{
	this->jobNumber = jobNumber;
	this->numberOfMachines = numberOfMachines;
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

int Job::getTimeJob(int machineNumber) const
{
	return jobTimeOnMachines.at(machineNumber-1);
}

int Job::getJobNumber() const
{
	return jobNumber;
}