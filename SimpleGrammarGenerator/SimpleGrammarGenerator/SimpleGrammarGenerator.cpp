// SimpleGrammarGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Grammar.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include "StudentInfo.h"
#include "ClassRoom.h"
#include "Vec.h"
#include "Vec.cpp"
#include "Dedicnost.h"
#include "StudentOper.h"
#include "Picture.h"

using namespace std;
void mainFc();
void VecMainFc();
void studentInfoMainFc();
void DedMainFc();

int main()
{
	try {
		//grammarGen();
		//studentInfoMainFc();
		//VeccMainFc();
		DedMainFc();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
	return 0;
}

void DedMainFc()
{
	vector<StudentOper> students;
	StudentOper item;
	string::size_type maxLen = 0;
	/*while (item.readStOper(cin))
	{
		maxLen = max(maxLen, item.name().size());
		students.push_back(item);
	}
	sort(students.begin(), students.end(), StudentOper::compareStOper);
	
	for (vector<StudentOper>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name()
			<< string(maxLen + 1 - students[i].name().size(), ' ');
		try {
			double finalMark = students[i].mark();
			streamsize presnost = cout.precision();
			cout << setprecision(3) << finalMark
				<< setprecision(presnost) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}*/

	BasicSt * p1 = new BasicSt;
	BasicSt *p2 = new CertSt;
	BasicSt s1;
	CertSt s2;
	p1->mark();
	p1->retName();

	p2->mark();
	p2->retName();
	s1.mark();
	s1.retName();

	s2.mark();
	s2.retName();
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

