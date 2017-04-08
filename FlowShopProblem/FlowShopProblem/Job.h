#pragma once
#include <vector>
#include <iostream>
#include <fstream>

class Job
{
private:
	int jobNumber;
	int numberOfMachines;
	std::vector<int> jobTimeOnMachines;
	int addedJobTimes;

	int getAndValidateData();
	void addJobTime();

public:
	explicit Job(const int jobNumber, const int numberOfMachines);
	~Job();

	bool initData();
	bool initData(std::fstream &file);

	void showData() const;

	int getTimeJob(const int machineNumber) const;
	int getJobNumber() const;

	bool operator < (const Job& other) const;
	
};

