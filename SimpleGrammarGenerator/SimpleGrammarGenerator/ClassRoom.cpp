#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "ClassRoom.h"
#include "StudentInfo.h"

using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
using std::endl;

ClassRoom::ClassRoom(const string& a, const string& b)
{
	this->name = a;
	this->location = b;
}

void ClassRoom::addStudent(const StudentInfo& st)
{
	if (st.isValid())
		this->students.push_back(st);
	else
		throw std::invalid_argument("empty student");
}

ostream& ClassRoom::writeClassR(ostream& os)
{
	if (os)
	{
		os << "Trida: " << this->name << " v ucebne: " << this->location << endl;
		os << "Studenti - Vysledky:" << this->students.size() << endl;
		for each(StudentInfo st in this->students)
		{
			os << st.name() << " Body: " << st.mark() << " Vysledek: " << st.finalSt() << endl;
		}
	}
	return os;
}

