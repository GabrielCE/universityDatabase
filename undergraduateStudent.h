// Header file for UndergraduateStudent class

#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H

#include "student.h"
#include <string>

class UndergraduateStudent : public Student
{
public:
	UndergraduateStudent();										// default constructor
	virtual ~UndergraduateStudent() {}							// virtual destructor
	
	void setGradeClassification(std::string);					// set student's grade classification
	std::string getGradeClassification();						// get student's grade classification
	
	void setGradeLevel(int);									// set student's grade level
	int getGradeLevel();										// get student's grade level
	
	virtual void print();										// print student information

private:
		int gradeLevel;
		std::string gradeName;
};

#endif