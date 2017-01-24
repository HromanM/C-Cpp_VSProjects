#include "stdafx.h"
#include "Dedicnost.h"
#include "StudentInfo.h"
#include <iostream>
#include <algorithm>

using std::istream;
using std::min;

double BasicSt::mark() const
{
	return ::markSt(half, exam, homeworks);
}

istream& BasicSt::readStComm(istream& is)
{
	is >> name >> half >> exam;
	return is;
}

istream& BasicSt::readSt(istream& is)
{
	readStComm(is);
	::readHw(is, homeworks);
	return is;
}

istream& CertSt::readSt(istream& is)
{
	readStComm(is);
	is >> project;
	::readHw(is, homeworks);
	return is;
}

double CertSt::mark() const
{
	return min(BasicSt::mark(), project);
}

bool compareStudent(const BasicSt& a, const BasicSt& b)
{
	return a.retName() < b.retName();
}

bool compareStudentPtr(const BasicSt* a, const BasicSt* b)
{
	return compareStudent(*a, *b);
}