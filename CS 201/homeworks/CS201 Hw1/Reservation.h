#ifndef RESERVATION_H
#define RESERVATION_H
#include "Flight.h"
#include "ReservationSystem.h"
using namespace std;
/*
**Name: Arman Engin Sucu
**ID: 21801777
*/

class Reservation {
public:
	//CONSTRUCTOR
	Reservation(int reservationCode, const int numPassengers, const int flightNo, const int* seatRow, const char* seatCol);
	Reservation();
	Reservation(const Reservation& reservation);
	~Reservation();

	//METHODS
	void setReservationCode(int reservationCode);
	void setNumPassengers(int numPassengers);
	void setFlightNo(int flightNo);
	void setSeatRow(const int* seatRow);
	void setSeatCol(const char* seatCol);
	int getFlightNo();
	int getReservationCode();
	int getNumPassengers();
	void cancelReservedSeats();
	const int* getSeatRow();
	const char* getSeatCol();

private:
	//PROPERTIES
	int reservationCode;
	int numPassengers;
	int flightNo;
	const int* seatRow;
	const char* seatCol;

public:
	//ASSIGNMENT OVERLOADING
	void operator =(const Reservation& flight);
};





















#endif
