// CPP file for ResearchAssistant class

#include <iostream>
#include "researchAssistant.h"

using namespace std;

// constructor
ResearchAssistant::ResearchAssistant() : GraduateStudent() {}
// end constructor

// setResearchTopic function
void ResearchAssistant::setResearchTopic(string topic){
	researchTopic = topic;
}
// end setResearchTopic function

// getResearchTopic function
string ResearchAssistant::getResearchTopic(){
	return researchTopic;
}
// end getResearchTopic function

// print function
void ResearchAssistant::print(){
	GraduateStudent::print();
	cout << "Research Topic: " << getResearchTopic() << endl;
}
// end print function