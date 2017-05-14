

#include "stdafx.h"
#include "Algorithm.h"
#include "NEH.h"
#include "SA.h"
#include "MTSA.h"
#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	array<string,1> files  {

		"../../Taillard/T20_5/T20_5.7.txt",

	};


	for (unsigned int i = 0; i < files.size(); i++)
	{
		cout << "-----------------------------------------------------------------------\n";
		cout << files.at(i) << "\n";
		cout << "SA\n";
		MTSA a;
		a.initData(files.at(i));
		a.computeResult();
		a.showResult();

		cout << "\n\n";
		cout << "NEH\n";
		NEH b;
		b.initData(files.at(i));
		b.computeResult();
		b.showResult();


	}

	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

