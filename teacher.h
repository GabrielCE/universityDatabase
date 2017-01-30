// Header file for Teacher class

#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <vector>

class Course;											// forward declaration

class Teacher : public Person
{
	std::vector<Course*> assignedCourses;
public:
	Teacher();											// default constructor
	virtual ~Teacher() {}								// virtual destructor

	void addAssignedCourse(Course*);					// add assigned course to teacher
		
	void setHoursWorking(int);					// set the amount of payable work hours
	int getHoursWorking();								// get the amount of payable work hours

	void setWagePerHour(double);						// set wage per hour worked
	double getWagePerHour();							// get wage per hour worked 
	
	double getYearlySalary();							// get amount of yearly income
	
	void printAssignedCourseNames();

	virtual void print();								// print teacher information
	
private:
	int courseNumber = 0;								// current assigned course counter
	int hoursWorking;									// amount of hours working	
	double wagePerHour;									// amount paid per hour worked
	double yearlySalary;								// yearly salary income
};

#endif
