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


	int getAndValidateData();

public:
	Job(int jobNumber, int numberOfMachines);
	~Job();

	bool initData();
	bool initData(std::fstream &file);

	void showData() const;

	int getTimeJob(int machineNumber) const;
	int getJobNumber() const;
	
};

