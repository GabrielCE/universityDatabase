// Header file for Department class

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <memory>

class Student;													// forward declaration
class Teacher;													// forward declaration
class Course;													// forward declaration

class Department
{
	std::vector<Student*> students;
	std::vector<Teacher*> teachers;
	std::vector<Course*> courses;
	
public:
	Department();												// default constructor
	virtual ~Department() {}									// virtual destructor
	
	void addStudent(Student*);									// add student to vector list
	void printStudents();										// print all students in department
	
	void addTeacher(Teacher*);									// add teacher to vector list
	void printTeachers();										// print all teachers in department
	
	void addCourse(Course*);									// add course to vector list
	void printCourses();										// print all teachers in department
	
	void setDepartmentTitle(std::string);						// set title of department
	std::string getDepartmentTitle();							// get title of department
	
	void print();												// print all department information

private:
	std::string departmentTitle;								// title of the department		
};

#endif