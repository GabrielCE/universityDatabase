// CPP file for Adjunct class

#include <iostream>
#include "adjunct.h"

using namespace std;

// constructor
Adjunct::Adjunct() : Teacher() {}
// end constructor

// setMaxHours function
void Adjunct::setMaxHours(int hours){
	maxHours = hours;
}
// end setMaxHours function

// getMaxHours function
int Adjunct::getMaxHours(){
	return maxHours;
}
// end getMaxHours function

// print function
void Adjunct::print(){
	Teacher::print();
	cout << "Max Hours: " << getMaxHours() << endl;
}
// end print function