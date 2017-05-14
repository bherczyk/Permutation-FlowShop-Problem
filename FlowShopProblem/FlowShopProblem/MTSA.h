//Multi-threaded simulated annealing algorithm for permutation flow shop problem. 
#pragma once
#include "SA.h"
class MTSA : public SA
{

public:
	explicit MTSA();
	~MTSA();

	virtual void computeResult();
};

