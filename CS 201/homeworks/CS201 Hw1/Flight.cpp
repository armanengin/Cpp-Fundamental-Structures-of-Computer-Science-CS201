#include "Flight.h"
#include "ReservationSystem.h"
#include <iostream>
using namespace std;

/*
* Name: Arman Engin SUCU
* ID: 21801777
**/

//CONSTRUCTORS
Flight::Flight(int flightNum, const int seatRow, const int seatCol, int currentNumPassengers){
	this->flightNum = flightNum;
	this->seatRow = seatRow;
	this->seatCol = seatCol;
	this->currentNumPassengers = currentNumPassengers;
	this->numOfAvalaibleSeats = seatRow * seatCol;
	this->seats = new int* [seatRow];
	for (int i = 0; i < seatRow; i++) {
		seats[i] = new int[seatCol];
	}
	//initializing garbage values for seats to 0
	for (int i = 0; i < seatRow; i++) {
		for (int j = 0; j < seatCol; j++) {
			seats[i][j] = 0;
		}
	}
}

Flight::Flight() {
	this->flightNum = 0;
	this->seatRow = 0;
	this->seatCol = 0;
	this->currentNumPassengers = 0;
	this->numOfAvalaibleSeats = seatRow * seatCol;
	this->seats = NULL;
}

Flight::Flight(const Flight& flight) {
		flightNum = flight.flightNum;
		seatRow = flight.seatRow;
		seatCol = flight.seatCol;
		currentNumPassengers = flight.currentNumPassengers;
		seats = new int* [seatRow];
		for (int i = 0; i < seatRow; i++) {
			seats[i] = new int[seatCol];
		}
		//initializing garbage values for seats to 0
		for (int i = 0; i < seatRow; i++) {
			for (int j = 0; j < seatCol; j++) {
				seats[i][j] = 0;
			}
		}
}

Flight::~Flight() {
	if (seats != NULL) {
		for (int i = 0; i < seatRow; i++) {
			delete[] seats[i];
		}
		delete[] seats;
	}
}

//ASSIGNMENT OVERLOADING
void Flight::operator =(const Flight& flight) {
	this->flightNum = flight.flightNum;
	this->seatRow = flight.seatRow;
	this->seatCol = flight.seatCol;
	this->currentNumPassengers = flight.currentNumPassengers;
	this->seats = new int* [seatRow];
	for (int i = 0; i < seatRow; i++) {
		this->seats[i] = new int[seatCol];
	}
	//initializing garbage values for seats to 0
	for (int i = 0; i < seatRow; i++) {
		for (int j = 0; j < seatCol; j++) {
			this->seats[i][j] = 0;
		}
	}
}

//METHODS
int Flight::getFlightNum() {
	return flightNum;
}

int Flight::getSeatRow() {
	return seatRow;
}

int Flight::getSeatCol() {
	return seatCol;
}

int** Flight::getSeats() {
	return seats;
}
void Flight::setFlightNum(int flightNum) {
	this->flightNum = flightNum;
}
void Flight::setSeatCol(int seatCol) {
	this->seatCol = seatCol;
}
void Flight::setSeatRow(int seatRow) {
	this->seatRow = seatRow;
}
void Flight::initializeSeats(int seatRow, int seatCol) {
	this->seats = new int* [seatRow];
	for (int i = 0; i < seatRow; i++) {
		seats[i] = new int[seatCol];
	}
	//initializing garbage values for seats to 0
	for (int i = 0; i < seatRow; i++) {
		for (int j = 0; j < seatCol; j++) {
			seats[i][j] = 0;
		}
	}
}

void Flight::setNumOfPassengers(int currentNumOfPassengers) {
	this->currentNumPassengers = currentNumOfPassengers;
}

void Flight::addNumPassengers(int numPassengers) {
	this->currentNumPassengers = (currentNumPassengers + numPassengers);
}
int Flight::getNumOfAvalaibleSeats() {
	numOfAvalaibleSeats = ((seatRow * seatCol) - currentNumPassengers);
	return numOfAvalaibleSeats;
}

//shows the detailed seat condition to user
void Flight::showSeatCondition() {
	char column = 'A';
	for (int i = 0; i < seatCol; i++) {
		cout << column << " ";
		column++;
	}
	cout << endl;
	for (int i = 0; i < seatRow; i++) {
		for (int j = 0; j < seatCol; j++) {
			if (j == 0) {
				cout << i + 1 << " ";
			}
			if (seats[i][j] == 0) {
				cout << "o ";
			}
			else {
				cout << "x ";
			}
		}
		cout << endl;
	}
}









