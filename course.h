// Header file for Course class

#ifndef COURSE_H
#define COURSE_H

#include <vector>

class Teacher;											// forward declaration
class Student;											// forward declaration
class TeachingAssistant;								// forward declaration


class Course
{
	std::vector<Student*> students;
	std::vector<Teacher*> teachers;
	std::vector<TeachingAssistant*> teachingAssistants;
	std::vector<int> grades;
public:
	Course();											// default constructor
	virtual ~Course() {}								// virtual destructor
	
	void setCourseName(std::string);					// set name of course
	std::string getCourseName();						// get name of course
	
	int getClassSize();									// get size of class
	
	void setCreditAmount(int);							// set amount of credits course is worth
	int getCreditAmount();								// get amount of credits course is worth
	
	void setGrade(int);									// set student grade
	int getNumberGrade(int);							// get student's number grade
	char getLetterGrade(int);							// get student's letter grade
	
	void setDepartmentTitle(std::string);				// set department of course
	std::string getDepartmentTitle();					// get department of course
	
	void addTeacher(Teacher*);							// add teacher to course
	void printTeachers();								// print information of all teachers
	
	void addStudent(Student*);							// add student to course
	void printStudents();								// print information of all students
	
	void addTeachingAssistant(TeachingAssistant*);		// add TA to course
	void printTeachingAssistants();						// print information of all teaching assistants
	
	void print();										// print course information
	
private:
	std::string courseName;								// name of course
	std::string departmentName;							// name of course's department
	int classSize = 0;									// amount of students in course
	int creditAmount;									// amount of credits course is worth
};

#endif