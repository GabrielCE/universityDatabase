// Header file for base class Person

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	Person();											// default constructor
	virtual ~Person() {}								// virtual destructor
		
	void setUniversityID(int);							// set UniversityID
	int getUniversityID();								// get UniversityID
		
	void setFirstName(std::string);						// set person's first name
	std::string getFirstName();							// get person's first name

	void setFamilyName(std::string);					// set person's family name
	std::string getFamilyName();						// get person's family name
	
	void setAge(int);									// set age of person
	int getAge();										// get age of person
	
	void setGender(std::string);						// set person's gender
	std::string getGender();							// get person's gender
	
	void setDepartment(std::string);					// set person's department
	std::string getDepartment();						// get person's department
		
	virtual void print();								// print person information
		
private:
	int universityID;									// person's university ID
	std::string firstName;								// person's first name
	std::string familyName;								// person's family name
	int age;											// person's age
	std::string gender;									// person's gender
	std::string department;
};

#endif
