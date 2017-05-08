#include "stdafx.h"
#include "SA.h"
#include <time.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

SA::SA()
{
	srand(time(0));
}


SA::~SA()
{
}


void SA::computeResult()
{
	const int MAX_ITER = 200 * numberOfJobs;
	const int MAX_ITER_FOR_FIXED_TEMP = numberOfJobs;
	double temp = INIT_TEMP;
	initialFirstSolution();


	
	for (int k = 0; k < 100; k++)
	{
		std::vector<Job> actualResultSchedule = resultSchedule;
		temp = INIT_TEMP;
		for (int iters = 0, itersForFixedTemp = 0, itersWithoutImprovement = 0; iters < MAX_ITER; itersForFixedTemp++, itersWithoutImprovement++)
		{
			std::vector<Job> newResultSchedule = insert(actualResultSchedule);
			int newMakespan = computeMakespan(newResultSchedule);
			if (newMakespan < makespan)
			{
				makespan = newMakespan;
				resultSchedule = newResultSchedule;
				actualResultSchedule = newResultSchedule;
				itersWithoutImprovement = 0;
			}
			else
			{
				double randomNumber = (double)rand() / (double)RAND_MAX;
				double acceptFunction = exp(-(newMakespan - makespan) / temp);
				if (randomNumber < acceptFunction)
				{
					actualResultSchedule = newResultSchedule;
				}
			}
			
			if (itersForFixedTemp == MAX_ITER_FOR_FIXED_TEMP)
			{
				temp *= ALPHA;
				iters++;
				itersForFixedTemp = 0;

			}
			if (itersWithoutImprovement == MAX_ITERS_WITHOUT_IMPROVEMENT)
			{
				temp = INIT_TEMP;
				itersWithoutImprovement = 0;
			}

		}
	}
}

void SA::initialFirstSolution()
{
	nehAlgorithm = std::unique_ptr<NEH>(new NEH(this));
	nehAlgorithm->computeResult();

	resultSchedule = nehAlgorithm->getResultSchedule();
	makespan = computeMakespan(resultSchedule);
}



std::vector<Job> SA::insert(const std::vector<Job>& actualResultSchedule)
{
	std::vector<Job> tmpResultSchedule = actualResultSchedule;
	int a = rand() % (numberOfJobs);
	int b = 0;
	while ((b = rand() % numberOfJobs) == a);
	Job tmp = tmpResultSchedule[a];
	auto it = tmpResultSchedule.begin();
	tmpResultSchedule.erase(it + a);
	tmpResultSchedule.insert(it + b, tmp);
	return tmpResultSchedule;
}

int SA::computeMakespan(const std::vector<Job>& resultSchedule)
{
	std::vector<std::vector<int>> completeTaskTime(numberOfJobs, std::vector<int>(numberOfMachines));

	for (int i = 0; i < numberOfJobs; i++)
	{
		for (int j = 0; j < numberOfMachines; j++)
		{

			int first = i > 0 ? completeTaskTime[i - 1][j] : 0;
			int second = j > 0 ? completeTaskTime[i][j - 1] : 0;

			int greaterTaskTime = max(first, second);
			completeTaskTime[i][j] = greaterTaskTime + resultSchedule[i].getTimeJob(j);

		}
	}
	return completeTaskTime.back().back();
}
