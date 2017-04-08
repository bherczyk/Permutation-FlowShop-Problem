#pragma once
#include "Algorithm.h"
#include <algorithm>
#include <queue>

class NEH : public Algorithm
{
private:
	std::priority_queue<Job> sortedJobs;

	void copyJobsToSortedJobs();
	
public:
	NEH();
	~NEH();

	virtual void computeResult();
};

