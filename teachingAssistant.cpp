// CPP file for TeachingAssistant class

#include <iostream>
#include "teachingAssistant.h"
#include "course.h"

using namespace std;

// constructor
TeachingAssistant::TeachingAssistant() : GraduateStudent() {}
// end constructor

// addAssignedCourse function
void TeachingAssistant::addAssignedCourse(Course* course){
	assignedCourses.push_back(course);
}
// end addAssignedCourse function

// print function
void TeachingAssistant::print(){
	GraduateStudent::print();
	cout << "Courses Assisting: ";
	for(int i = 0; i < assignedCourses.size(); i++){
		if (i < assignedCourses.size() - 1)
			cout << assignedCourses.at(i)->getCourseName() << ", ";
		else
			cout << assignedCourses.at(i)->getCourseName() << endl;
	}
}
// end print function