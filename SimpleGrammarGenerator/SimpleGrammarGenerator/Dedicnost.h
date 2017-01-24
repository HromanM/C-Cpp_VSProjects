#pragma once

#include<iostream>
#include<vector>
#include<string>

class BasicSt
{
public:
	BasicSt() : half(0), exam(0) { std::cout << "BasicSt()" << std::endl; }
	BasicSt(std::istream& is) { readSt(is); std::cout << "BasicSt(istream)" << std::endl;}
	virtual ~BasicSt() {}
	std::string retName() const { return name; }
	virtual std::istream& readSt(std::istream&);
	friend class StudentOper;
	template<class T> friend class ServiceClass;
	virtual double mark() const;
	virtual void newMark(double d) { exam = exam + 1000; }
protected:
	std::istream& readStComm(std::istream&);
	double half, exam;
	std::vector<double> homeworks;
	virtual BasicSt* cloneSt() const { return new BasicSt(*this); }
private:
	std::string name;
};

class CertSt : public BasicSt
{
public:
	CertSt() : project(0) { std::cout << "CertSt()" << std::endl; }
	CertSt(std::istream& is) { readSt(is); std::cout << "CertSt(istream)" << std::endl;
	}
	double mark() const;
	std::istream& readSt(std::istream&);
	void newMark(double d) { exam = exam + 10000; }
protected:
	virtual CertSt* cloneSt() const { return new CertSt(*this); }
private:
	double project;
};

bool compareStudent(const BasicSt&, const BasicSt&);
bool compareStudentPtr(const BasicSt*, const BasicSt*);