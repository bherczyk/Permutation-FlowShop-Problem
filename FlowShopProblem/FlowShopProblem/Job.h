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

	bool initialData();
	bool initialData(std::fstream &file);

	void showData() const;
	
};

