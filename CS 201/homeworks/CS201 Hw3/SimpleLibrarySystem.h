/*
@Author: Arman Engin Sucu
@ID: 21801777
@Section: 02
*/
#ifndef SIMPLELIBRARYSYSTEM_H
#define SIMPLELIBRARYSYSTEM_H
#include <iostream>
#include "SimpleStudent.h"

using namespace std;
class Student;
class LibrarySystem {

public:
	//CONSTRUCTORS
	LibrarySystem();
	~LibrarySystem();

	//ASSIGNMENTS METHODS
	void addStudent(const int studentId, const string studentName);
	void deleteStudent(const int studentId);
	void showStudent(const int studentId) const;

private:
	struct studentNode {
		Student item;
		studentNode* next;
		studentNode* precede;
	};

	//PROPERTIES
	studentNode* head;
	int numOfStudents;

public:
	//METHODS
	studentNode* findStudent(const int id) const;

};
#endif