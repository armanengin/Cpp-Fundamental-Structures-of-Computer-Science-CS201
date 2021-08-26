/*
@Author: Arman Engin Sucu
@ID: 21801777
@Section: 02
*/
#include "SimpleLibrarySystem.h"
#include<iostream>
using namespace std;

//CONSTRUCTORS
LibrarySystem::LibrarySystem() {
	head = NULL;
	numOfStudents = 0;
}

LibrarySystem::~LibrarySystem() {
	while (numOfStudents > 0) {
		studentNode* curr = head;
		head = head->next;
		curr->next = NULL;
		curr->precede = NULL;
		delete curr; 
		curr = NULL;
		numOfStudents--;
}

}

//ASSIGNMENT METHODS
//add elements to circular doubly linkedlist
void LibrarySystem::addStudent(const int studentId, const string studentName){
	if (findStudent(studentId) != NULL) {
		cout << "Student " << studentId << " already exists." << endl;
	}
	else {
		studentNode *node = new studentNode;
		if (head == NULL) {
			head = node;
			node->item = Student(studentId, studentName);
			head->next = node; //points to itself
			head->precede = node; //points to itself
		}
		else {
			studentNode* lastNode = head->precede;
			head->precede = node;
			node->item = Student(studentId, studentName);
			lastNode->next = node;
			node->precede = lastNode;
			node->next = head;
		}
		cout << "Student " << studentId << " has been added." << endl;
		numOfStudents++;
	}
}

void LibrarySystem::deleteStudent(const int studentId) {
	if (findStudent(studentId) == NULL) {
		cout << "Student " << studentId << " doesn't exist." << endl;
	}
	else {
		studentNode* curr = findStudent(studentId);
		if (curr == head) {
			studentNode* prev = curr->precede;
			prev->next = curr->next;
			curr->next->precede = prev;
			head = curr->next;
		}
		else {
			studentNode* prev = curr->precede;
			prev->next = curr->next;
			curr->next->precede = prev;
		}
		curr->next = NULL;
		curr->precede = NULL;
		delete curr;
		curr = NULL;
		cout << "Student " << studentId << " has been deleted." << endl;
		numOfStudents--;
	}

}

void LibrarySystem::showStudent(const int studentId) const {
	studentNode* student = findStudent(studentId);
	if (student == NULL) {
		cout << "Student " << studentId << " does not exist." << endl;
	}
	else {
		cout << "Student id: " << studentId << " student name: " << findStudent(studentId)->item.getName() << endl;
	}
}

//HELPER METHODS
LibrarySystem::studentNode* LibrarySystem::findStudent(const int id) const {
	if (head == NULL) {
		return NULL;
	}
	else {
		studentNode* cur = head;
		do{
			if (cur->item.getId() == id) {
				return cur;
			}
			cur = cur->next;
		}while (cur != head);
		return NULL;
	}
}