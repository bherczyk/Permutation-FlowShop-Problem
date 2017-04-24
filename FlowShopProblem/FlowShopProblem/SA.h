#pragma once
#include "Algorithm.h"
#include "NEH.h"
#include <memory>
class SA : public Algorithm
{
private:
	static const int INIT_TEMP = 60;
	static constexpr double ALPHA = 0.98;
	static const int MAX_ITERS_WITHOUT_IMPROVEMENT = 10;

	std::unique_ptr<NEH> nehAlgorithm;

	void initialFirstSolution();
	std::vector<Job> insert(const std::vector<Job> &actualResultSchedule);

	int computeMakespan(const std::vector<Job> &resultSchedule);
	
public:
	explicit SA();
	~SA();

	virtual void computeResult();
};

