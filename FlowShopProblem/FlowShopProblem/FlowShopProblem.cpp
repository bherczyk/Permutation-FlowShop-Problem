

#include "stdafx.h"
#include "Algorithm.h"
#include "NEH.h"
#include "SA.h"
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	SA a;
	a.initData("../../Taillard/T100_10/T100_10.1.txt");
	//a.showData();
	a.computeResult();
	a.showResult();

	NEH c;

	c.initData("../../Taillard/T100_10/T100_10.1.txt");
	c.computeResult();
	c.showResult();

	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

