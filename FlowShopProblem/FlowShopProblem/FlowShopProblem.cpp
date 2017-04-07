

#include "stdafx.h"
#include "Algorithm.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Algorithm a;
	a.initData();
	a.showData();
	a.tests();
	a.showResult();
	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

