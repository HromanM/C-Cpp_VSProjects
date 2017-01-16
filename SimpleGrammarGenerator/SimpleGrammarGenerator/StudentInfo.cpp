#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "StudentInfo.h"

using std::istream;
using std::string;
using std::vector;
using std::invalid_argument;

istream& StudentInfo::readSt(istream& is)
{
	is >> nameSt >> half >> exam;
	::readHw(is, homework);
	return is;
}
double StudentInfo::mark() const
{
	return ::markSt(this->half, this->exam, this->homework);
}

StudentInfo::StudentInfo() : half(0), exam(0){}

StudentInfo::StudentInfo(istream& is) { this->readSt(is); }

char StudentInfo::finalSt()
{
	if (this->mark() >= 60)
		return 'P';
	else
		return 'N';
}

double markSt(double half, double exam, vector<double> hw)
{
	double homew = 0;
	if (hw.empty())
		throw invalid_argument("homework is empty");
	for each (double d in hw)
		homew += d;
	return 0.4*half + 0.4*exam + homew / hw.size();
}

istream& readHw(istream& is, vector<double> & hw)
{
	double d;
	while (is >> d)
		hw.push_back(d);
	return is;
}

bool compareSt(const StudentInfo& x, const StudentInfo& y)
{
	return x.name() < y.name();
}