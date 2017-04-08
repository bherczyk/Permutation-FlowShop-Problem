#pragma once
#include "Algorithm.h"
#include <algorithm>
#include <queue>

class NEH : public Algorithm
{
private:
	

	void copyJobsToSortedJobs(std::priority_queue<Job> &sortedJobs);
	void checkNewMakespan(int &tmpMakespan, std::vector<Job> &tmpResultSchedule);
	void findNewSchedule(int &numberOfJobsInResult, Job &job, std::vector<Job> &tmpResultSchedule);

public:
	NEH();
	~NEH();

	virtual void computeResult();
};

