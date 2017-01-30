// CPP file for Person class

#include <iostream>
#include "person.h"

using namespace std;

//constructor
Person::Person() {}
// end constructor

// setUniversityID function
void Person::setUniversityID(int ID){
	universityID = ID;
}
// end setUniversityID function

// getUniversityID function
int Person::getUniversityID(){
	return universityID;
}
// end getUniversityID function

// setFirstName function
void Person::setFirstName(string personName){
	firstName = personName;
}
// end setFirstName function

// getFirstName function
string Person::getFirstName(){
	return firstName;
}
// end getFirstName function

// setFamilyName function
void Person::setFamilyName(string lastName){
	familyName = lastName;
}
// end setFamilyName function

// getFamilyName function
string Person::getFamilyName(){
	return familyName;
}
// end getFamilyName function

// setAge function
void Person::setAge(int number){
	age = number;
}
// end setAge function

// getAge function
int Person::getAge(){
	return age;
}
// end getAge function

// setGender function
void Person::setGender(string genderInput){
	gender = genderInput;
}
// end setGender function

// getGender function
string Person::getGender(){
	return gender;
}
// end getGender function

// setDepartment function
void Person::setDepartment(string title){
	department = title;
}
// end setDepartment function

// getDepartment function
string Person::getDepartment(){
	return department;
}
// end getDepartment function

// print function
void Person::print(){
	cout << "Name: " << getFirstName() << " " << getFamilyName() << endl;
	cout << "UID: " << getUniversityID() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Department: " << getDepartment() << endl;
}
// end print function
