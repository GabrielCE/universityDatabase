// Header file for Adjunct class

#ifndef ADJUNCT_H
#define ADJUNCT_H

#include "teacher.h"

class Adjunct : public Teacher
{
public:
	Adjunct();											// default constructor
	virtual ~Adjunct() {}								// virtual destructor
	
	void setMaxHours(int);								// set adjunct's max payable hours(default 20)
	int getMaxHours();									// get adjunct's max payable hours
		
	virtual void print();								// print adjunct information
	
private:
	int maxHours;
};

#endif