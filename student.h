//	Header file for Student class

#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <vector>

class Course;										// forward declaration	

class Student : public Person
{
	std::vector<Course*> courses;
public:
	Student();										// default constructor
	virtual ~Student() {}							// virtual destructor

	void addCourse(Course*);						// add course to student
	
	int getCurrentCreditAmount();					// get credit cap
	
	void printCourseNames();
	
	virtual void print();							// print student information
	
private:
	int currentCreditAmount = 0;
};

#endif