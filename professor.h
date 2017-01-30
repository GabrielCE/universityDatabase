// Header file for Professor class

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "lecturer.h"
#include <string>

class Professor : public Lecturer
{
public:
	Professor();										// default constructor
	virtual ~Professor() {}								// virtual destructor
	
	void setTenureDuration(int);						// set amount of days left on tenure
	int getTenureDuration();							// get amount of days left on tenure
	
	void setResearchTopic(std::string);					// set professor's research topic
	std::string getResearchTopic();						// get professor's research topic
	
	virtual void print();								// print professor's information

private:
	int tenureDays;										// amount of days left on tenure
	std::string researchTopic;							// professor's research topic

};

#endif