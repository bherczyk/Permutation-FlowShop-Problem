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
	std::vector<Job> resultSchedule;

	int computeMakespan(const int jobsInResultSchedule);
	int max(const int first, const int second);

public:
	explicit Algorithm();
	virtual ~Algorithm();

	bool initData();
	bool initData(const std::string fileName);

	void showData() const;
	void showResult() const;

	virtual void computeResult() = 0;

};

