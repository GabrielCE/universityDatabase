// Header file for Lecturer class

#ifndef LECTURER_H
#define LECTURER_H

#include "teacher.h"

class Lecturer : public Teacher
{
public:
	Lecturer();										// default constructor
	virtual ~Lecturer() {}							// virtual destructor
	
	void setMinimumHours(int);						// set lecturer's minimum hours of payable weekly income
	int getMinimumHours();							// get lecturer's minimum hours of payable weekly income
	
	virtual void print();							// print lecturer's information
	
private:
	int minimumHours;
};

#endif