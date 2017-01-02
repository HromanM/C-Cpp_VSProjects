// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include "AuxFunctions.h"
#include "AuxFunctions.h"

using namespace std;

void mainFc()
{
	map<string, vector<int> > crossL = crossLink(cin);

	for (map<string, vector<int> >::const_iterator it = crossL.begin();
		it != crossL.end(); ++it)
	{
		cout << it->first << " se nachází na pozicích: ";
		vector<int>::const_iterator radekIter = it->second.begin();
		cout << *radekIter;
		++radekIter;
		while (radekIter != it->second.end())
		{
			cout << ", " << *radekIter;
			radekIter++;
		}
		cout << endl;
	}


}

int main()
{
	try
	{
		mainFc();
	}
	catch (exception e)
	{
		cout << "Error" << endl;
	}
	return 0;
}


