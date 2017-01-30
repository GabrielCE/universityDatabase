// *************************************************************//
//																//
//	Author: Gabriel Contreras									//
//	Program: University database								//
//																//
//**************************************************************//

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <string>
#include <memory>

#include "department.h"
#include "course.h"
#include "person.h"
#include "student.h"
#include "undergraduateStudent.h"
#include "graduateStudent.h"
#include "teachingAssistant.h"
#include "researchAssistant.h"
#include "teacher.h"
#include "adjunct.h"
#include "lecturer.h"
#include "professor.h"

using namespace std;

int main(){
	vector<Student*> students;
	vector<Teacher*> teachers;
	vector<Course*> courses;
	vector<Department*> departments;
	
	int iType, iTemp, peekCheck;
	int departmentCounter = 0;
	int courseCounter = 0;
	char sTemp[256];
	double dTemp;
	
	{//Input of all data from text files to objects		
	
// inputing from departments.txt into department objects
	
	// ifstream constructor to open departments.txt file
	ifstream inDepartmentFile("departments.txt", ios::in);
	
	// exits program if ifstream could not open departments.txt
	if(!inDepartmentFile){
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	inDepartmentFile.ignore(numeric_limits<streamsize>::max(), '\n');
	while(!inDepartmentFile.eof()){
		departments.push_back(new Department());
		inDepartmentFile.getline(sTemp, 256, '|');
		departments.at(departmentCounter++)->setDepartmentTitle(sTemp);
		inDepartmentFile.getline(sTemp, 256);
	}
	inDepartmentFile.close();
// end inputing from departments.txt
	
// inputing from courses.txt into course objects

	// ifstream constructor to open courses.txt file
	ifstream inCourseFile("courses.txt", ios::in);
	
	if(!inCourseFile){
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
	inCourseFile.ignore(numeric_limits<streamsize>::max(), '\n');
	while(!inCourseFile.eof()){
		courses.push_back(new Course());
		inCourseFile.getline(sTemp, 8, ' ');
		inCourseFile.ignore(256, '|');
		courses.at(courseCounter)->setCourseName(sTemp);
		
		inCourseFile.getline(sTemp, 25, '|');
		courses.at(courseCounter)->setDepartmentTitle(sTemp);
		
		for(int i = 0; i < departments.size(); i++){
			if(courses.at(courseCounter)->getDepartmentTitle() == departments.at(i)->getDepartmentTitle())
				departments.at(i)->addCourse(courses.at(courseCounter));
		}
		
		inCourseFile >> iTemp;
		courses.at(courseCounter++)->setCreditAmount(iTemp);
		inCourseFile.getline(sTemp, 256);	
	}
	inCourseFile.close();
// end inputing from courses.txt

// inputing from students.txt into student objects
	
	// ifstream constructor to open students.txt file
	ifstream inStudentFile("students.txt", ios::in);
	
	if(!inStudentFile){
		cerr<< "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
	inStudentFile.ignore(numeric_limits<streamsize>::max(), '\n');
	inStudentFile.ignore(numeric_limits<streamsize>::max(), '\n');
	while(!inStudentFile.eof()){
		inStudentFile >> iType;
		peekCheck = 0;
		inStudentFile.getline(sTemp, 256, '|');

		if(iType == 1){
			UndergraduateStudent* type = 0;
			type = new UndergraduateStudent();
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);
			inStudentFile.ignore(256, '|');
		
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inStudentFile.ignore(256, '|');
		
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setAge(iTemp);
		
			inStudentFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
		
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setUniversityID(iTemp);
		
			inStudentFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);
			
			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addStudent(type);
			}
			
			while(true){
				peekCheck = inStudentFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inStudentFile.getline(sTemp, 256, '(');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addCourse(courses.at(i));
						courses.at(i)->addStudent(type);
						inStudentFile >> iTemp;
						courses.at(i)->setGrade(iTemp);
						inStudentFile.getline(sTemp, 256, '-');
					}
				}
			}

			inStudentFile.ignore(256, '|');
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setGradeLevel(iTemp);

			inStudentFile.getline(sTemp, 256, '|');
			type->setGradeClassification(sTemp);
			students.push_back(type);
			inStudentFile.getline(sTemp,256);

		}
		if (iType == 2){
			GraduateStudent* type = 0;
			type = new GraduateStudent();
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);
			inStudentFile.ignore(256, '|');
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inStudentFile.ignore(256, '|');
			
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setAge(iTemp);
			
			inStudentFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
			
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setUniversityID(iTemp);
			
			inStudentFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);

			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addStudent(type);
			}

			while(true){
				peekCheck = inStudentFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inStudentFile.getline(sTemp, 256, '(');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addCourse(courses.at(i));
						courses.at(i)->addStudent(type);
						inStudentFile >> iTemp;
						courses.at(i)->setGrade(iTemp);
						inStudentFile.getline(sTemp, 256, '-');
					}
				}
			}
			inStudentFile.ignore(256, '|');
			inStudentFile.ignore(256, '|');
			inStudentFile.ignore(256, '|');
			inStudentFile.getline(sTemp, 256, '|');
			type->setSpecialization(sTemp);
			students.push_back(type);
			inStudentFile.getline(sTemp,256);
			
		}
		if (iType == 3){
			ResearchAssistant* type = 0;
			type = new ResearchAssistant();
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);		
			inStudentFile.ignore(256, '|');
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inStudentFile.ignore(256, '|');
			
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setAge(iTemp);
			
			inStudentFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
			
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setUniversityID(iTemp);
			
			inStudentFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);
			
			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addStudent(type);
			}
			
			while(true){
				peekCheck = inStudentFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inStudentFile.getline(sTemp, 256, '(');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addCourse(courses.at(i));
						courses.at(i)->addStudent(type);
						inStudentFile >> iTemp;
						courses.at(i)->setGrade(iTemp);
						inStudentFile.getline(sTemp, 256, '-');
					}
				}
			}
			inStudentFile.ignore(256, '|');
			inStudentFile.ignore(256, '|');
			inStudentFile.ignore(256, '|');
			inStudentFile.getline(sTemp, 256, '|');
			type->setSpecialization(sTemp);
				
			inStudentFile.getline(sTemp, 256, '|');
			type->setResearchTopic(sTemp);
			students.push_back(type);
			inStudentFile.getline(sTemp,256);			
		}
		
		if (iType == 4){
			TeachingAssistant* type = 0;
			type = new TeachingAssistant();
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);
			inStudentFile.ignore(256, '|');
			
			inStudentFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inStudentFile.ignore(256, '|');
			
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setAge(iTemp);
			
			inStudentFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
			
			inStudentFile >> iTemp;
			inStudentFile.ignore(256, '|');
			type->setUniversityID(iTemp);
			
			inStudentFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);
			
			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addStudent(type);
			}
			
			while(true){
				peekCheck = inStudentFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inStudentFile.getline(sTemp, 256, '(');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addCourse(courses.at(i));
						courses.at(i)->addStudent(type);
						inStudentFile >> iTemp;
						courses.at(i)->setGrade(iTemp);
						inStudentFile.getline(sTemp, 256, '-');
					}
				}
			}
			for(int i = 0; i < 4; i++){
				inStudentFile.getline(sTemp, 256, '|');
			}
			type->setSpecialization(sTemp);
			
			inStudentFile.ignore(256, '|');	
			while(true){
				peekCheck = inStudentFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inStudentFile.getline(sTemp, 256, '-');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addAssignedCourse(courses.at(i));
						courses.at(i)->addTeachingAssistant(type);
					}
				}
			}
			students.push_back(type);	
			inStudentFile.getline(sTemp, 256);
		}
		
	}
	inStudentFile.close();
// end inputing from students.txt

// inputing from teachers.txt into teacher objects
	
	// ifstream constructor to open teachers.txt file
	ifstream inTeacherFile("teachers.txt", ios::in);
	
	if(!inTeacherFile){
		cerr<< "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
	inTeacherFile.ignore(numeric_limits<streamsize>::max(), '\n');
	inTeacherFile.ignore(numeric_limits<streamsize>::max(), '\n');
	while(!inTeacherFile.eof()){
		inTeacherFile >> iType;
		peekCheck = 0;
		inTeacherFile.getline(sTemp, 256, '|');
		if(iType == 1){
			Adjunct* type = 0;
			type = new Adjunct();
			
			inTeacherFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setAge(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setUniversityID(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);
			
			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addTeacher(type);
			}
			
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setMaxHours(iTemp);
			
			inTeacherFile >> dTemp;
			inTeacherFile.ignore(256, '|');
			type->setWagePerHour(dTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setHoursWorking(iTemp);
			
			inTeacherFile.ignore(256, '|');
			inTeacherFile.ignore(256, '|');
			
			
			while(true){
				peekCheck = inTeacherFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inTeacherFile.getline(sTemp, 256, '-');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addAssignedCourse(courses.at(i));
						courses.at(i)->addTeacher(type);
					}
				}
			}
			teachers.push_back(type);
			inTeacherFile.getline(sTemp, 256);
		}
		if(iType == 2){
			Lecturer* type = 0;
			type = new Lecturer();
			
			inTeacherFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setAge(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setUniversityID(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);
			
			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addTeacher(type);
			}
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setMinimumHours(iTemp);
			
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile >> dTemp;
			inTeacherFile.ignore(256, '|');
			type->setWagePerHour(dTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setHoursWorking(iTemp);
			
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile.ignore(256, '|');
			
			while(true){
				peekCheck = inTeacherFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inTeacherFile.getline(sTemp, 256, '-');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addAssignedCourse(courses.at(i));
						courses.at(i)->addTeacher(type);
					}
				}
			}
			teachers.push_back(type);
			inTeacherFile.getline(sTemp, 256);
			
		}
		if(iType == 3){
			Professor* type = 0;
			type = new Professor();
			
			inTeacherFile.getline(sTemp, 256, ' ');
			type->setFirstName(sTemp);
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile.getline(sTemp, 256, ' ');
			type->setFamilyName(sTemp);
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setAge(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setGender(sTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setUniversityID(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setDepartment(sTemp);
			
			for(int i = 0; i < departments.size(); i++){
				if(type->getDepartment() == departments.at(i)->getDepartmentTitle())
					departments.at(i)->addTeacher(type);
			}
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setMinimumHours(iTemp);
			
			inTeacherFile.ignore(256, '|');
			
			inTeacherFile >> dTemp;
			inTeacherFile.ignore(256, '|');
			type->setWagePerHour(dTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setHoursWorking(iTemp);
			
			inTeacherFile.getline(sTemp, 256, '|');
			type->setResearchTopic(sTemp);
			
			inTeacherFile >> iTemp;
			inTeacherFile.ignore(256, '|');
			type->setTenureDuration(iTemp);
			
			while(true){
				peekCheck = inTeacherFile.peek();
				if(peekCheck == ' ' || peekCheck == '|')
					break;
				inTeacherFile.getline(sTemp, 256, '-');
				for(int i = 0; i < courses.size(); i++){
					if(sTemp == courses.at(i)->getCourseName()){
						type->addAssignedCourse(courses.at(i));
						courses.at(i)->addTeacher(type);
					}
				}
			}
			teachers.push_back(type);
			inTeacherFile.getline(sTemp, 256);
			
		}
	}
		

	inTeacherFile.close();
	
// end inputing from teachers.txt

}

	{//Test portion of main function

	//Print information of a student object
	cout << "Print Student test:" << endl << endl;
	
	students.at(0)->print();
	cout << endl << endl;
	
	//Print information of a teacher object
	cout << "Print Teacher test:" << endl << endl;
	
	teachers.at(0)->print();
	cout << endl << endl;
	
	//Print information of a student object through a person object
	cout << "Print Person -> Student test:" << endl << endl;
	
	Person* obj1 = students.at(1);
	obj1->print();
	cout << endl << endl;
	
	//Print information of a teacher object through a person object
	cout << "Print Person->Teacher test:" << endl << endl;
	
	Person* obj2 = teachers.at(1);
	obj2->print();
	cout << endl << endl;
	
	//Print student names and ID's who are enrolled in a course
	cout << "Print Course -> Students test:" << endl << endl;
	
	cout << "Course Name: " << courses.at(1)->getCourseName() << endl;
	courses.at(1)->printStudents();
	cout << endl << endl;
	
	//Print course names which student is enrolled in
	cout << "Print Student -> Courses test:" << endl << endl;
	
	students.at(2)->printCourseNames();
	cout << endl << endl;
	
	//Print teachers assigned to a course
	cout << "Print Course -> Teachers test: " << endl << endl;
	
	cout << "Course Name: " << courses.at(4)->getCourseName() << endl;
	courses.at(1)->printTeachers();
	cout << endl << endl;
	
	//Print courses that teacher teaches
	cout << "Print Teacher -> Courses test: " << endl << endl;
	
	teachers.at(2)->printAssignedCourseNames();
	cout << endl << endl;
	
	//Print department students, courses, or teachers(example of all three)
	cout << "Print Department -> (Students/Courses/Teachers):" << endl << endl;
	
	cout << "Department Name: " << departments.at(0)->getDepartmentTitle() << endl;
	departments.at(0)->printStudents();
	departments.at(0)->printCourses();
	departments.at(0)->printTeachers();
	
	

/*	for(int i = 0; i < departments.size(); i++){
		departments.at(i)->print();
		cout << endl <<endl;
	}
	for(int i = 0; i < courses.size(); i++){
		courses.at(i)->print();
		cout << endl <<endl;
	}*/
	}
	return 0;
}