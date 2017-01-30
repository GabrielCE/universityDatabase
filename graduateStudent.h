// Header file for GraduateStudent class

#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "student.h"
#include <string>

class GraduateStudent : public Student
{
public:
	GraduateStudent();										// default constructor
	virtual ~GraduateStudent() {}							// virtual destructor
	
	void setSpecialization(std::string);					// set student's specialization
	std::string getSpecialization();						// get student's specialization
	
	virtual void print();									// print student's information

private:
	std::string specialization;								// student's specialization
};

#endif