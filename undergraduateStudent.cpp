// CPP file for UndergraduateStudent class

#include <iostream>
#include "undergraduateStudent.h"

using namespace std;

// constructor
UndergraduateStudent::UndergraduateStudent() : Student() {}
// end constructor

// setGradeClassification function
void UndergraduateStudent::setGradeClassification(string classification){
	gradeName = classification;
}
// end setGradeClassification function

// getGradeClassification function
string UndergraduateStudent::getGradeClassification(){
	return gradeName;
}
// end getGradeClassification function

// setGradeLevel function
void UndergraduateStudent::setGradeLevel(int level){
	gradeLevel = level;
}
// end setGradeLevel function

// getGradeLevel function
int UndergraduateStudent::getGradeLevel(){
	return gradeLevel;
}
// end getGradeLevel function

// print function
void UndergraduateStudent::print(){
	Student::print();
	cout << "Grade level: " << getGradeLevel() << endl;	
	cout << "Grade Classification: " << getGradeClassification() << endl;
}
// end print function