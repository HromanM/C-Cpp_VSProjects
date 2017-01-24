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
	return half + exam + homew / hw.size();
}

istream& readHw(istream& is, vector<double> & hw)
{
	if (is)
	{
		hw.clear();

		double d;
		while (is >> d)
			hw.push_back(d);
		is.clear();
	}
	return is;
}

bool compareSt(const StudentInfo& x, const StudentInfo& y)
{
	return x.name() < y.name();
}

string markChar(double mark)
{
	static const double numValues[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0 };

	static const char* const cMarks[] = {
		"A+", "A", "A-","B+", "B", "B-","C+", "C", "C-","D", "F"
	};

	static const size_t valCount = sizeof(numValues) / sizeof(*numValues);

	for (size_t i = 0; i < valCount; ++i)
	{
		if (mark >= numValues[i])
			return cMarks[i];
	}
	return "?/?/?";
}