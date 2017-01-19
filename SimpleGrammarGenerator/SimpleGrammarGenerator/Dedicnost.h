#pragma once

#include<iostream>
#include<vector>
#include<string>

class BasicSt
{
public:
	BasicSt() : half(0), exam(0) {}
	BasicSt(std::istream& is) { readSt(is); }
	std::string retName() const { return name; }
	std::istream& readSt(std::istream&);
	virtual double mark() const;
protected:
	std::istream& readStComm(std::istream&);
	double half, exam;
	std::vector<double> homeworks;
private:
	std::string name;
};

class CertSt : public BasicSt
{
public:
	CertSt() : project(0) {}
	CertSt(std::istream& is) { readSt(is); }
	double mark() const;
	std::istream& readSt(std::istream&);
private:
	double project;
};

bool compareSt(const BasicSt& a, const BasicSt& b)
{
	return a.retName() < b.retName();
}