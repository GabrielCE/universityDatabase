// Header file for ResearchAssistant class

#ifndef RESEARCHASSISTANT_H
#define RESEARCHASSISTANT_H

#include "graduateStudent.h"
#include <string>

class ResearchAssistant : public GraduateStudent
{
public:
	ResearchAssistant();							// default constructor
	virtual ~ResearchAssistant() {}					// virtual destructor

	void setResearchTopic(std::string);				// set student's research topic
	std::string getResearchTopic();					// get student's research topic
	
	virtual void print();							// print student information
	
private:
	std::string researchTopic;						// student's research topic
};

#endif