#include "stdafx.h"
#include "NEH.h"


NEH::NEH() : Algorithm()
{
}


NEH::~NEH()
{
}


NEH::NEH(const Algorithm* a)
{
	const NEH *other = static_cast<const NEH*>(a);
	this->numberOfJobs = other->numberOfJobs;
	this->numberOfMachines = other->numberOfMachines;
	this->jobs = other->jobs;
}
void NEH::computeResult()
{
	std::priority_queue<Job> sortedJobs;
	std::vector<Job> tmpResultSchedule;
	copyJobsToSortedJobs(sortedJobs);
	int numberOfJobsInResult = 0;
	while (!sortedJobs.empty())
	{
		if (numberOfJobsInResult == 0)
		{
			Job job = sortedJobs.top();
			sortedJobs.pop();
			numberOfJobsInResult++;
			resultSchedule.push_back(job);
		}
		numberOfJobsInResult++;
		Job job = sortedJobs.top();
		sortedJobs.pop();
		findNewSchedule(numberOfJobsInResult, job, tmpResultSchedule);
	}
	makespan = computeMakespan(numberOfJobs);
}

void NEH::copyJobsToSortedJobs(std::priority_queue<Job> &sortedJobs)
{
	for (auto it = jobs.begin(); it != jobs.end(); it++)
	{
		sortedJobs.push(*it);
	}
}

void NEH::findNewSchedule(int &numberOfJobsInResult, Job &job, std::vector<Job> &tmpResultSchedule)
{
	int tmpMakespan = INT_MAX;
	auto it = resultSchedule.begin();
	for (int i = 0; i < numberOfJobsInResult; i++)
	{
		it = resultSchedule.insert(it + i, job);
		makespan = computeMakespan(numberOfJobsInResult);
		checkNewMakespan(tmpMakespan, tmpResultSchedule);
		resultSchedule.erase(it);
		it = resultSchedule.begin();
	}
	resultSchedule.clear();
	resultSchedule = tmpResultSchedule;
}

void NEH::checkNewMakespan(int &tmpMakespan, std::vector<Job> &tmpResultSchedule)
{
	if (tmpMakespan > makespan)
	{
		tmpResultSchedule.clear();
		tmpResultSchedule = resultSchedule;
		tmpMakespan = makespan;
	}
}

int NEH::getMakespan() const
{
	return makespan;
}

std::vector<Job> NEH::getResultSchedule() const
{
	return resultSchedule;
}