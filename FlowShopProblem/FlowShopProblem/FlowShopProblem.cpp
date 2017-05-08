

#include "stdafx.h"
#include "Algorithm.h"
#include "NEH.h"
#include "SA.h"
#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	array<string,40> files  {"../../Taillard/T20_5/T20_5.1.txt",
		"../../Taillard/T20_5/T20_5.2.txt",
		"../../Taillard/T20_5/T20_5.3.txt",
		"../../Taillard/T20_5/T20_5.4.txt",
		"../../Taillard/T20_5/T20_5.5.txt",
		"../../Taillard/T20_5/T20_5.6.txt",
		"../../Taillard/T20_5/T20_5.7.txt",
		"../../Taillard/T20_5/T20_5.8.txt",
		"../../Taillard/T20_5/T20_5.9.txt",
		"../../Taillard/T20_5/T20_5.10.txt",
		"../../Taillard/T20_10/T20_10.1.txt",
		"../../Taillard/T20_10/T20_10.2.txt",
		"../../Taillard/T20_10/T20_10.3.txt",
		"../../Taillard/T20_10/T20_10.4.txt",
		"../../Taillard/T20_10/T20_10.5.txt",
		"../../Taillard/T20_10/T20_10.6.txt",
		"../../Taillard/T20_10/T20_10.7.txt",
		"../../Taillard/T20_10/T20_10.8.txt",
		"../../Taillard/T20_10/T20_10.9.txt",
		"../../Taillard/T20_10/T20_10.10.txt",
		"../../Taillard/T20_20/T20_20.1.txt",
		"../../Taillard/T20_20/T20_20.2.txt",
		"../../Taillard/T20_20/T20_20.3.txt",
		"../../Taillard/T20_20/T20_20.4.txt",
		"../../Taillard/T20_20/T20_20.5.txt",
		"../../Taillard/T20_20/T20_20.6.txt",
		"../../Taillard/T20_20/T20_20.7.txt",
		"../../Taillard/T20_20/T20_20.8.txt",
		"../../Taillard/T20_20/T20_20.9.txt",
		"../../Taillard/T20_20/T20_20.10.txt",
		"../../Taillard/T50_5/T50_5.1.txt",
		"../../Taillard/T50_5/T50_5.2.txt",
		"../../Taillard/T50_5/T50_5.3.txt",
		"../../Taillard/T50_5/T50_5.4.txt",
		"../../Taillard/T50_5/T50_5.5.txt",
		"../../Taillard/T50_5/T50_5.6.txt",
		"../../Taillard/T50_5/T50_5.7.txt",
		"../../Taillard/T50_5/T50_5.8.txt",
		"../../Taillard/T50_5/T50_5.9.txt",
		"../../Taillard/T50_5/T50_5.10.txt",
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

