

#include "stdafx.h"
#include "Algorithm.h"
#include "NEH.h"
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	NEH a;
	a.initData();
	a.computeResult();
	a.showResult();
	//a.computeResult();
	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

