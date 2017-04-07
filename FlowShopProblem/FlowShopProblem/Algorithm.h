#pragma once
#include <string>
#include "Job.h"
#include <list>


class Algorithm
{
private:
	int getAndValidateData();

protected:
	int numberOfMachines;
	int numberOfJobs;
	std::vector<Job> jobs;
	int makespan;
	std::list<Job> resultSchedule;

public:
	Algorithm();
	~Algorithm();

	bool initialData();
	bool initialData(const std::string fileName);

	void showData() const;
	void showResult() const;
};

