

#include "stdafx.h"
#include "Algorithm.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Algorithm a;
	a.initialData("../../Taillard/T20_5/t20_5.1.txt");
	a.showData();
	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

