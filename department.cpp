// CPP file for Department class

#include <iostream>
#include <string>
#include "department.h"
#include "student.h"
#include "teacher.h"
#include "course.h"

using namespace std;

// constructor
Department::Department() {}
// end constructor

// addStudent function
void Department::addStudent(Student* student){
	students.push_back(student);
}
// end addStudent function

// printStudents function
void Department::printStudents(){
	cout << "Student Names: ";
	for(int i = 0; i < students.size(); i++){
		if(i < students.size() - 1)
			cout << students.at(i)->getFirstName() << " " << students.at(i)->getFamilyName() << ", ";
		else
			cout << students.at(i)->getFirstName() << " " << students.at(i)->getFamilyName() << endl;
	}
}
// end printStudents function

// addTeacher function
void Department::addTeacher(Teacher* teacher){
	teachers.push_back(teacher);
}
// end addTeacher function

// dropTeacher function

// printTeachers function
void Department::printTeachers(){
	cout << "Teacher Names: ";
	for(int i = 0; i < teachers.size(); i++){
		if(i < teachers.size()-1)
			cout << teachers.at(i)->getFirstName() << " " << teachers.at(i)->getFamilyName() << ", ";
		else
			cout << teachers.at(i)->getFirstName() << " " << teachers.at(i)->getFamilyName() << endl;
	}
}
// end printTeachers function

// addCourse function
void Department::addCourse(Course* course){
	courses.push_back(course);
}
// end addCourse function

// printCourses function
void Department::printCourses(){
	cout << "Course Names: ";
	for(int i = 0; i < courses.size(); i++){
		if(i < courses.size()-1)
			cout << courses.at(i)->getCourseName() << ", ";
		else
			cout << courses.at(i)->getCourseName() << endl;
	}
}
// end printCourses function

// setDepartmentTitle function
void Department::setDepartmentTitle(string title){
	departmentTitle = title;
}
// end setDepartmentTitle function

// getDepartmentTitle funcion
string Department::getDepartmentTitle(){
	return departmentTitle;
}
// end getDepartmentTitle funcion

// print function
void Department::print(){
	cout << "Department: " << departmentTitle << endl;
	printTeachers();
	printCourses();
	printStudents();
}
// end print funcion