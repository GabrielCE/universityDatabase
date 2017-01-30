// CPP file for GraduateStudent class

#include <iostream>
#include "graduateStudent.h"

using namespace std;

// constructor
GraduateStudent::GraduateStudent() : Student() {}
// end constructor

// setSpecialization function
void GraduateStudent::setSpecialization(string specName){
	specialization = specName;
}
// end setSpecialization function

// getSpecialization function
string GraduateStudent::getSpecialization(){
	return specialization;
}
// end getSpecialization function

// print function
void GraduateStudent::print(){
	Student::print();
	cout << "Specialization: " << specialization << endl;
}
// end print function