// CPP file for Lecturer class

#include <iostream>
#include "lecturer.h"

using namespace std;

// constructor
Lecturer::Lecturer() : Teacher() {}
// end constructor

// setMinimumHours function
void Lecturer::setMinimumHours(int hours){
	minimumHours = hours;
}
// end setMinimumHours function

// getMinimumHours function
int Lecturer::getMinimumHours(){
	return minimumHours;
}
// end getMinimumHours function

// print function
void Lecturer::print(){
	Teacher::print();
	cout << "Minimum hours: " << getMinimumHours() << endl;
}
// end print function