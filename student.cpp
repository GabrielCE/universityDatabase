// CPP file for Student class

#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

// constructor
Student::Student():Person() {}
// end constructor

// addCourse function
void Student::addCourse(Course* course){

		courses.push_back(course);
		currentCreditAmount += course->getCreditAmount();
}
// end addCourse function

// getCurrentCreditAmount function
int Student::getCurrentCreditAmount(){
	return currentCreditAmount;
}
// end getCurrentCreditAmount function

// printCourseNames function
void Student::printCourseNames(){
	cout << "Student Name: " << Person::getFirstName() << " " << Person::getFamilyName() << endl;
	cout << "Courses:";
	for(int i = 0; i < courses.size(); i++){
		if (i < courses.size() - 1)
			cout << courses.at(i)->getCourseName() << ", ";
		else
			cout << courses.at(i)->getCourseName() << endl;
	}
}
// end printCourseNames function

// print function
void Student::print(){
	Person::print();
	cout << "Courses: ";
	for(int i = 0; i < courses.size(); i++){
		if (i < courses.size() - 1)
			cout << courses.at(i)->getCourseName() << ", ";
		else
			cout << courses.at(i)->getCourseName() << endl;
	}
	cout << "Current Credit Amount: " << getCurrentCreditAmount() << endl;
}
// end print function