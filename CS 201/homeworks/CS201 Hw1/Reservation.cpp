#include "Reservation.h"
#include<iostream>
#include "ReservationSystem.h"
using namespace std;

/*
**Name: Arman Engin Sucu
**ID: 21801777
*/

//COSTRUCTORS
Reservation::Reservation(int reservationCode, const int numPassengers, const int flightNo, const int* seatRow, const char* seatCol) {
	this->reservationCode = reservationCode;
	this->numPassengers = numPassengers;
	this->flightNo = flightNo;
	this->seatRow = seatRow;
	this->seatCol = seatCol;
}
Reservation::Reservation() {
	this->reservationCode = 0;
	this->numPassengers = 0;
	this->flightNo = 0;
	this->seatRow = 0;
	this->seatCol = 0;
}

Reservation::Reservation(const Reservation& reservation) {
	this->reservationCode = reservation.reservationCode;
	this->numPassengers = reservation.numPassengers;
	this->flightNo = reservation.flightNo;
	this->seatRow = reservation.seatRow;
	this->seatCol = reservation.seatCol;
}

Reservation::~Reservation() {

}

//ASSIGNMENT OVERLOADING
void Reservation::operator =(const Reservation& reservation) {
	this->reservationCode = reservation.reservationCode;
	this->numPassengers = reservation.numPassengers;
	this->flightNo = reservation.flightNo;
	this->seatRow = reservation.seatRow;
	this->seatCol = reservation.seatCol;
}

//METHODS
void Reservation::setReservationCode(int reservationCode) {
	this->reservationCode = reservationCode;
}

void Reservation::setNumPassengers(int numPassengers) {
	this->numPassengers = numPassengers;
}

void Reservation::setFlightNo(int flightNo) {
	this->flightNo = flightNo;
}
void Reservation::setSeatRow(const int* seatRow) {
	this->seatRow = seatRow;
}
void Reservation::setSeatCol(const char* seatCol) {
	this->seatCol = seatCol;
}
int Reservation::getFlightNo() {
	return flightNo;
}
int Reservation::getReservationCode() {
	return reservationCode;
}
int Reservation::getNumPassengers() {
	return numPassengers;
}

const int* Reservation::getSeatRow() {
	return seatRow;
}

const char* Reservation::getSeatCol() {
	return seatCol;
}

