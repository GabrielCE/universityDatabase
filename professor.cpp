// CPP file for Professor class

#include <iostream>
#include "professor.h"

using namespace std;

// constructor
Professor::Professor() : Lecturer() {}
// end constructor

// setTenureDuration function
void Professor::setTenureDuration(int days){
	tenureDays = days;
}
// end setTenureDuration function

// getTenureDuration function
int Professor::getTenureDuration(){
	return tenureDays;
}
// end getTenureDuration function

// setResearchTopic function
void Professor::setResearchTopic(string topic){
	researchTopic = topic;
}
// end setResearchTopic function

// getResearchTopic function
string Professor::getResearchTopic(){
	return researchTopic;
}
// end getResearchTopic function

// print function
void Professor::print(){
	Lecturer::print();
	cout << "Tenure Duration(Days): " << getTenureDuration() << endl;
	cout << "Research Topic: " << getResearchTopic() << endl;
}
// end print function