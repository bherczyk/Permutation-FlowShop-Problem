

#include "stdafx.h"
#include "Algorithm.h"
#include "NEH.h"
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	NEH a;
	a.initData("../../Taillard/T100_20/T100_20.1.txt");
	a.showData();
	a.computeResult();
	a.showResult();

	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

