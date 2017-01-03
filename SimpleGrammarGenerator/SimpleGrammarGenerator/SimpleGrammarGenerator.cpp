// SimpleGrammarGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Grammar.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
void mainFc();

int main()
{
	try {
		mainFc();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
    return 0;
}

void mainFc()
{
	vector<string> sentence = sentenceGenerator(readGrammar(cin));

	vector<string>::const_iterator iter = sentence.begin();
	if (!sentence.empty())
	{
		cout << *iter;
		++iter;
	}

	while (iter != sentence.end())
	{
		cout << " " << *iter;
		++iter;
	}
	cout << endl;
}
