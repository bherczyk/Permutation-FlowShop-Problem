#include "stdafx.h"
#include "MTSA.h"


MTSA::MTSA()
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


MTSA::~MTSA()
{
}

void MTSA::computeResult()
{
}
