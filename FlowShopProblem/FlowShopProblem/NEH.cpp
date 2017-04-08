#include "stdafx.h"
#include "NEH.h"


NEH::NEH() : Algorithm()
{
}


NEH::~NEH()
{
}

void NEH::computeResult()
{
	std::vector<Job> tmpResultSchedule;
	
	copyJobsToSortedJobs();
	int numberOfJobsInResult = 0;

	while (!sortedJobs.empty())
	{
		int tmpMakespan = INT_MAX;
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
		
		auto it = resultSchedule.begin();
		for (int i = 0; i < numberOfJobsInResult; i++)
		{	
			it = resultSchedule.insert(it + i, job);
			computeMakespan(numberOfJobsInResult);
			if (tmpMakespan > makespan)
			{
				tmpResultSchedule.clear();
				tmpResultSchedule = resultSchedule;
				tmpMakespan = makespan;
			}
			resultSchedule.erase(it);
			it = resultSchedule.begin();
		}
		resultSchedule.clear();
		resultSchedule = tmpResultSchedule;
	}
	computeMakespan(numberOfJobsInResult);
	
}

void NEH::copyJobsToSortedJobs()
{
	for (auto it = jobs.begin(); it != jobs.end(); it++)
	{
		sortedJobs.push(*it);
	}
}