#pragma once

class StudentInfo {
	private:
		std::string nameSt;
		double half, exam;
		std::vector<double> homework;

	public:
		std::istream &readSt(std::istream&);
		double mark() const;
		std::string name() const { return this->nameSt; }
		bool isValid() const { return !this->homework.empty(); }
		double examRes() const { return this->exam; }
		StudentInfo();
		StudentInfo(std::istream&);
		char finalSt();
};

double markSt(double, double, std::vector<double>);
std::istream& readHw(std::istream&, std::vector<double> &);
bool compareSt(const StudentInfo&, const StudentInfo&);