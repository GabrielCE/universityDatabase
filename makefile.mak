
main: main.o person.o student.o undergraduateStudent.o graduateStudent.o researchAssistant.o teachingAssistant.o teacher.o adjunct.o lecturer.o professor.o department.o course.o
	g++ main.o person.o student.o undergraduateStudent.o graduateStudent.o researchAssistant.o teachingAssistant.o teacher.o adjunct.o lecturer.o professor.o department.o course.o -o main
	
main.o: main.cpp department.h course.h person.h student.h undergraduateStudent.h graduateStudent.h teachingAssistant.h researchAssistant.h teacher.h adjunct.h lecturer.h professor.h
	g++ -c main.cpp
	
person.o: person.cpp person.h
	g++ -c person.cpp
	
student.o: student.cpp student.h course.h
	g++ -c student.cpp
	
undergraduateStudent.o: undergraduateStudent.cpp undergraduateStudent.h
	g++ -c undergraduateStudent.cpp
	
graduateStudent.o: graduateStudent.cpp graduateStudent.h
	g++ -c graduateStudent.cpp
	
researchAssistant.o: researchAssistant.cpp researchAssistant.h
	g++ -c researchAssistant.cpp
	
teachingAssistant.o: teachingAssistant.cpp teachingAssistant.h course.h
	g++ -c teachingAssistant.cpp
	
teacher.o: teacher.cpp teacher.h course.h
	g++ -c teacher.cpp
	
adjunct.o: adjunct.cpp adjunct.h
	g++ -c adjunct.cpp

lecturer.o: lecturer.cpp lecturer.h
	g++ -c lecturer.cpp
	
professor.o: professor.cpp professor.h
	g++ -c professor.cpp

department.o: department.cpp department.h course.h student.h teacher.h
	g++ -c department.cpp

course.o: course.cpp course.h teacher.h student.h teachingAssistant.h
	g++ -c course.cpp
	
clean: 
	rm rf *o main