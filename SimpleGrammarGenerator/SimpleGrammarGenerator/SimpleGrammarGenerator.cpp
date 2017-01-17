// SimpleGrammarGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Grammar.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "StudentInfo.h"
#include "ClassRoom.h"

using namespace std;
void mainFc();

int main()
{
	try {
		//grammarGen();
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
	ClassRoom cr("4.A", "17A");
	StudentInfo st;
	while(1)
	{
		st.readSt(cin);
		cr.addStudent(st);
		cout << "Student pridan" << endl;
		if (!cin)
			break;
	}
	cr.writeClassR(cout);
}

void grammarGen()
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