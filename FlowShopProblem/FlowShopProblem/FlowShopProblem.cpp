

#include "stdafx.h"
#include "Algorithm.h"
#include "NEH.h"
#include "SA.h"
#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	array<string,2> files  {

		"../../Taillard/T50_10/T50_10.7.txt",
		"../../Taillard/T50_10/T50_10.8.txt",



	};


	for (int i = 0; i < files.size(); i++)
	{
		cout << "-----------------------------------------------------------------------\n";
		cout << files.at(i) << "\n";
		cout << "SA\n";
		SA a;
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
	//SA a;
	//a.initData("../../Taillard/T50_20/T50_20.1.txt");
	////a.showData();
	//a.computeResult();
	//a.showResult();

	//NEH c;

	//c.initData("../../Taillard/T50_20/T50_20.1.txt");
	//c.computeResult();
	//c.showResult();

	std::cin.clear();
	std::cin.ignore();
	int b;
	std::cin >> b;
	return 0;
}

