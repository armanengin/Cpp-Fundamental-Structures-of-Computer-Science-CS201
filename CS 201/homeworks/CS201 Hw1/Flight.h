#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H
using namespace std;

/*
**Name: Arman Engin Sucu
**ID: 21801777
*/
class Flight {
public:
	//CONSTRUCTORS
	Flight(int flightNum, int seatRow, int seatCol, int currentNumPassengers);
	Flight(const Flight& flight);
	Flight();
	~Flight();

	//METHODS
	int getFlightNum();
	int getSeatRow();
	int getSeatCol();	
	int** getSeats();
	int getNumOfAvalaibleSeats();
	void setFlightNum(int flightNum);
	void setSeatCol(int seatCol);
	void setSeatRow(int seatRow);
	void initializeSeats(int seatRow, int seatCol);
	void setNumOfPassengers(int numOfPassengers);
	void addNumPassengers(int numPassengers);
	//void reserveSeats(const int* seatRow, const char* seatCol, const int numPassengers);
	void showSeatCondition();
	int* charArrToIntArr(const char* seatCol, const int numPassengers);

private:
	//PROPERTIES
	int flightNum;
	int seatCol;
	int seatRow;
	int** seats;
	int currentNumPassengers;
	int numOfAvalaibleSeats;

public:
	//ASSIGNMENT OVERLOADING
	void operator =(const Flight& flight);
};











#endif