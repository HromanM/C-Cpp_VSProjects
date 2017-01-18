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
#include "Vec.h"
#include "Vec.cpp"

using namespace std;
void mainFc();
void VecMainFc();
void studentInfoMainFc();

int main()
{
	try {
		//grammarGen();
		//studentInfoMainFc();
		VecMainFc();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
    return 0;
}

void VecMainFc()
{
	Vec<int> vec1;
	Vec<int> vec2(5, 2);
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	cout << "Size: " << vec1.size() <<  "prvek[max]: " << vec1[vec1.size() - 1] << endl;
	vec1.pop_back();
	cout << "Size: " << vec1.size() << "prvek[max]: " << vec1[vec1.size() - 1] << endl;
	Vec<int> vec3 = vec1;
	cout << "Size: " << vec3.size() << "prvek[max]: " << vec3[vec3.size() - 1] << endl;
	vec3.clear();
	cout << "Size: " << vec3.size() << "prvek[max]: " << vec3[vec3.size() - 1] << endl;

}

void studentInfoMainFc()
{
	ClassRoom cr("4.A", "17A");
	StudentInfo st;
	while (1)
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

