//Multi-threaded simulated annealing algorithm for permutation flow shop problem. 
#pragma once
#include "SA.h"
#include <thread>
#include <mutex>
#include <atomic>
#include <random>

class MTSA : public SA
{

private:
	std::mutex mtx;
	std::atomic<bool> readyReadResultSchedule = true;
	void simulatedAnnealing();
	std::vector<Job> insert(const std::vector<Job> &actualResultSchedule);

public:
	explicit MTSA();
	~MTSA();

	virtual void computeResult();
};

