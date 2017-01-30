// CPP file for Course class

#include <iostream>
#include "course.h"
#include "teacher.h"
#include "student.h"
#include "teachingAssistant.h"

using namespace std;

// constructor
Course::Course() {}
// end constructor

// setCourseName function
void Course::setCourseName(string name){
	courseName = name;
}
// end setCourseName function

// getCourseName function
string Course::getCourseName(){
	return courseName;
}
// end getCourseName function

// getClassSize function
int Course::getClassSize(){
	classSize = students.size();
	return classSize;
}
// end getClassSize function

// setCreditAmount function
void Course::setCreditAmount(int credits){
	creditAmount = credits;
}
// end setCreditAmount function

// getCreditAmount function
int Course::getCreditAmount(){
	return creditAmount;
}
// end getCreditAmount function

// setGrade function
void Course::setGrade(int grade){
	if(grade <= 100 & grade >= 0){
		grades.push_back(grade);
	} else
		cout << "Please input grade between 0-100.";
}
// end setGrade function

// getNumberGrade function
int Course::getNumberGrade(int studentID){
	for(int i = 0; i < students.size(); i++){
		if(students.at(i)->getUniversityID() == studentID)
			return grades.at(i);
	}
}
// end getNumberGrade function

// getLetterGrade function
char Course::getLetterGrade(int studentID){
	int temp = getNumberGrade(studentID);
	char letter;
	
	if(temp <= 100 || temp >= 90)
		letter = 'A';
	else if (temp <= 89 || temp >= 80)
		letter = 'B';
	else if (temp <= 79 || temp >= 70)
		letter = 'C';
	else if (temp <= 69 || temp >= 65)
		letter = 'D';
	else if (temp <= 64 || temp >= 0 )
		letter = 'F';
	else
		cout << "Grade input outside of range." << endl;
	return letter;
}
// end getLetterGrade function

// setDepartmentTitle function
void Course::setDepartmentTitle(string name){
	departmentName = name;
}
// end setDepartmentTitle function

// getDepartmentTitle function
std::string Course::getDepartmentTitle(){
	return departmentName;
}
// end getDepartmentTitle function

// addTeacher function
void Course::addTeacher(Teacher* teacher){
	teachers.push_back(teacher);
}
// end addTeacher function

// printTeachers function
void Course::printTeachers(){
	cout << "Teacher Names: ";
	for(int i = 0; i < teachers.size(); i++){
		if(i < teachers.size() - 1)
			cout << teachers.at(i)->getFirstName() << " " << teachers.at(i)->getFamilyName() << ", ";
		else
			cout << teachers.at(i)->getFirstName() << " " << teachers.at(i)->getFamilyName() << endl;
	}
}
// end printTeachers function

// addStudent function
void Course::addStudent(Student* student){
	students.push_back(student);
}
// end addStudent function


// printStudents function
void Course::printStudents(){
	cout << "Student Names(ID)[Grade]: ";
	for(int i = 0; i < students.size(); i++){
		if(i < students.size() - 1)
			cout << students.at(i)->getFirstName() << " " << students.at(i)->getFamilyName() << " (U" << students.at(i)->getUniversityID() << ") [" <<getLetterGrade(students.at(i)->getUniversityID()) << " " << getNumberGrade(students.at(i)->getUniversityID()) << "], ";
		else
			cout << students.at(i)->getFirstName() << " " << students.at(i)->getFamilyName() << " (U" << students.at(i)->getUniversityID() << ") [" <<getLetterGrade(students.at(i)->getUniversityID()) << " " << getNumberGrade(students.at(i)->getUniversityID()) << "]" <<  endl;
	}
}
// end printStudents function

// addTeachingAssistant function
void Course::addTeachingAssistant(TeachingAssistant* TA){
	teachingAssistants.push_back(TA);
}
// end addTeachingAssistant function


// printTeachingAssistants function
void Course::printTeachingAssistants(){
	cout << "Teaching Assistant Names: ";
	for(int i = 0; i < teachingAssistants.size(); i++){
		if(i < teachingAssistants.size() - 1)
			cout << teachingAssistants.at(i)->getFirstName() << " " << teachingAssistants.at(i)->getFamilyName() << ", ";
		else
			cout << teachingAssistants.at(i)->getFirstName() << " " << teachingAssistants.at(i)->getFamilyName() << endl;
	}
}
// end printTeachingAssistants function

// print function
void Course::print(){
	cout << "Course Name: " << getCourseName() << endl;
	cout << "Department: " << getDepartmentTitle() << endl;
	cout << "Credit Amount: " << getCreditAmount() << endl;
	cout << "Class Size: " << getClassSize() << endl;
	printTeachers();
	printStudents();
	printTeachingAssistants();
}
// end print function