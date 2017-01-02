// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string s;
	map<string, int> pocitadla;

	while (cin >> s)
	{
		++pocitadla[s];
	}

	for (map<string, int>::const_iterator it = pocitadla.begin(); it != pocitadla.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
    return 0;
}


