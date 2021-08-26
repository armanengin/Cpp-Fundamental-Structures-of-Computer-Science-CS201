/*
@Author: Arman Engin Sucu
@ID: 21801777
@Section: 02
*/
#include "SimpleStudent.h"
#include <iostream>
using namespace std;

//COSTRUCTORS
Student::Student(int id, string name) {
	this->id = id;
		this->name = name;
}
Student::Student() {
	id = 0;
	name = "";
}
//METHODS
int Student::getId() {
	return id;
}

string Student::getName() {
	return name;
}

void Student::setId(int id) {
	this->id = id;
}

void Student::setName(string name) {
	this->name = name;
}

