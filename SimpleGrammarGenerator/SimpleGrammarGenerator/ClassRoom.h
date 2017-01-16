#pragma once

#include "StudentInfo.h"

class ClassRoom {
	public:
		std::string retName() const { return this->name; }
		std::string retLocation() const { return this->location; }
		std::vector<StudentInfo> retStudents() const {return this->students; }
		ClassRoom(const std::string&, const std::string&);
		void addStudent(const StudentInfo&);
		std::ostream& writeClassR(std::ostream&);
	private:
		std::string name;
		std::string location;
		std::vector<StudentInfo> students;
};