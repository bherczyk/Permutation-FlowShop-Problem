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

	void computeMakespan(const int jobsInResultSchedule);
	int max(int first, int second);
public:
	Algorithm();
	~Algorithm();

	bool initData();
	bool initData(const std::string fileName);

	void showData() const;
	void showResult() const;

	void tests();

	
};

