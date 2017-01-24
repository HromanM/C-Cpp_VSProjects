#pragma once

#include "Dedicnost.h"
#include "ServiceClass.h"
#include "ServiceClass.cpp"

class StudentOper {
public:
	StudentOper() {}
	StudentOper(std::istream& is) { readStOper(is); }

	std::istream& readStOper(std::istream&);
	
	std::string name() const
	{
		if (zu) return zu->retName();
		else throw std::runtime_error("Uninitialized student.");
	}

	double mark() const
	{
		if (zu) return zu->mark();
		else throw std::runtime_error("Uninitialized student.");
	}

	static bool compareStOper(const StudentOper& s1, const StudentOper& s2)
	{
		return s1.name() < s2.name();
	}
	
private:
	ServiceClass<BasicSt> zu;
};
