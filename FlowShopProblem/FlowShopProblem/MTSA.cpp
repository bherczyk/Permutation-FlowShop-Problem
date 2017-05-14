#include "stdafx.h"
#include "MTSA.h"




MTSA::MTSA()
{
	
}


MTSA::~MTSA()
{
}

void MTSA::computeResult()
{
	
	initialFirstSolution();

	const int numberOfThread = 8;
	std::vector<std::thread> threads;

	for (int i = 0; i < numberOfThread; i++)
	{
		std::thread t(&MTSA::simulatedAnnealing, this);
		threads.push_back(std::move(t));
	}
	for (auto &t : threads)
	{
		t.join();
	}
}

void MTSA::simulatedAnnealing()
{
	const int MAX_ITER = 200 * numberOfJobs;
	const int MAX_ITER_FOR_FIXED_TEMP = numberOfJobs;
	for (int k = 0; k < 5; k++)
	{
		while (!readyReadResultSchedule)
		{
			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::vector<Job> actualResultSchedule = resultSchedule;
		

		double temp = INIT_TEMP;
		for (int iters = 0, itersForFixedTemp = 0, itersWithoutImprovement = 0; iters < MAX_ITER; itersForFixedTemp++, itersWithoutImprovement++)
		{
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


			std::vector<Job> newResultSchedule = insert(actualResultSchedule);
			int newMakespan = computeMakespan(newResultSchedule);
		
			{
				std::lock_guard<std::mutex> mutexManager(mtx);
				if (newMakespan < makespan)
				{
					readyReadResultSchedule = false;
					makespan = newMakespan;
					resultSchedule = newResultSchedule;
					readyReadResultSchedule = true;

					actualResultSchedule = newResultSchedule;
					itersWithoutImprovement = 0;
					continue;
				}
			}
			
			std::random_device randomDevice;
			std::mt19937 generator(randomDevice());
			std::uniform_real_distribution<>range(0, 1);
			double randomNumber = range(generator);
			double acceptFunction = exp(-(newMakespan - makespan) / temp);
			if (randomNumber < acceptFunction)
			{
				actualResultSchedule = newResultSchedule;
			}
		}
	}
}




std::vector<Job> MTSA::insert(const std::vector<Job>& actualResultSchedule)
{
	std::vector<Job> tmpResultSchedule = actualResultSchedule;
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<> range(0, numberOfJobs - 1);
	int a = range(generator);
	int b = 0;
	while ((b = range(generator)) == a);
	Job tmp = tmpResultSchedule[a];
	auto it = tmpResultSchedule.begin();
	tmpResultSchedule.erase(it + a);
	tmpResultSchedule.insert(it + b, tmp);
	return tmpResultSchedule;
}