// Header file for TeachingAssistant class

#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "graduateStudent.h"
#include <vector>

class Course;												// forward declaration			

class TeachingAssistant : public GraduateStudent
{
	std::vector<Course*> assignedCourses;
public:
	TeachingAssistant();									// default constructor
	virtual ~TeachingAssistant() {}							// virtual destructor
	
	void addAssignedCourse(Course*);						// add course that student assists
		
	virtual void print();									// print student information
};

#endif