//NEH algorithm for permutation flow shop problem 
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
	explicit NEH();
	NEH(const Algorithm* a);
	~NEH();

	virtual void computeResult();

	int getMakespan() const;
	std::vector<Job> getResultSchedule() const;
};

