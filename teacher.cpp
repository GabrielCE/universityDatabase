// CPP file for Teacher class

#include <iostream>
#include "teacher.h"
#include "course.h"

using namespace std;

// constructor
Teacher::Teacher() : Person() {}
// end constructor

// addAssignedCourse function
void Teacher::addAssignedCourse(Course* assignedCourse){
	assignedCourses.push_back(assignedCourse);
}
// end addAssignedCourse function

// setHoursWorking function
void Teacher::setHoursWorking(int hours){
	hoursWorking = hours;
}
// end setHoursWorking function

// getHoursWorking function
int Teacher::getHoursWorking(){
	return hoursWorking;
}
// end getHoursWorking function

// setWagePerHour function
void Teacher::setWagePerHour(double wage){
	wagePerHour = wage;
}
// end setWagePerHour function

// getWagePerHour function
double Teacher::getWagePerHour(){
	return wagePerHour;
}
// end getWagePerHour function

// getYearlySalary function
double Teacher::getYearlySalary(){
	yearlySalary = wagePerHour * hoursWorking * 49;
	return yearlySalary;
}
// end getYearlySalary function

// printAssignedCourseNames function
void Teacher::printAssignedCourseNames(){
	cout << "Teacher Name: " << Person::getFirstName() << " " << Person::getFamilyName() << endl;
	cout << "Course Names: ";
	for(int i = 0; i < assignedCourses.size(); i++){
		if (i < assignedCourses.size() - 1)
			cout << assignedCourses.at(i)->getCourseName() << ", ";
		else
			cout << assignedCourses.at(i)->getCourseName() << endl;
	}
}

// print function
void Teacher::print(){
	Person::print();
	cout << "Hours working: " << getHoursWorking() << endl;
	cout << "Wage per hour: " << getWagePerHour() << endl;
	cout << "Yearly income: " << getYearlySalary() << endl;
	cout << "Courses teaching: ";
	for(int i = 0; i < assignedCourses.size(); i++){
		if (i < assignedCourses.size() - 1)
			cout << assignedCourses.at(i)->getCourseName() << ", ";
		else
			cout << assignedCourses.at(i)->getCourseName() << endl;
	}
	
}
// end print function