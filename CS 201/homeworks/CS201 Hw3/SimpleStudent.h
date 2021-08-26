/*
@Author: Arman Engin Sucu
@ID: 21801777
@Section: 02
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student {
	//PROPERTIES
	private:
		int id;
		string name;
public:
	//CONSTRUCTORS
		Student(int id, string name);
		Student();

	//METHODS
		int getId();
		string getName();
		void setId(int id);
		void setName(string name);

};
#endif
