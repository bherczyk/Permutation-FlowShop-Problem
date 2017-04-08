#pragma once
#include <string>
#include "Job.h"
#include <list>


class Algorithm
{
private:
	int getAndValidateData();
	int max(const int first, const int second);

protected:
	int numberOfMachines;
	int numberOfJobs;
	std::vector<Job> jobs;
	int makespan;
	std::vector<Job> resultSchedule;

	void computeMakespan(const int jobsInResultSchedule);
	

public:
	explicit Algorithm();
	virtual ~Algorithm();

	bool initData();
	bool initData(const std::string fileName);

	void showData() const;
	void showResult() const;

	virtual void computeResult() = 0;

};

