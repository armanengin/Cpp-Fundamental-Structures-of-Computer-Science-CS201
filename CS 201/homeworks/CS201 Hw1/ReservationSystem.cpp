#include "ReservationSystem.h"
#include "Reservation.h"
#include <iostream>
#include <string>

using namespace std;

/*
* Name: Arman Engin SUCU
* ID: 21801777
**/

//CONSTRUCTORS
ReservationSystem::ReservationSystem() {
	flightArr = NULL;
	sizeFlightArr = 0;
	reservationArr = NULL;
	totalReservations = 0;
	reservationCode = 1;
	flightSize = 0;
	intArrForColumns = NULL;
	indexes = NULL;
	indexesSize = 0;
}

ReservationSystem::~ReservationSystem() {
	if (flightArr != NULL) {
		delete[] flightArr;
	}
	if (reservationArr != NULL) {
		delete[] reservationArr;
	}
	if (intArrForColumns != NULL) {
		delete[] intArrForColumns;
	}
	if (indexes != NULL) {
		delete[] indexes;
	}
}

//METHODS

//add flight to flightArr
void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo) {
	
	if (flightArr == NULL) {
		flightArr = new Flight(flightNo, rowNo, seatNo, 0);
		cout << "Flight " << flightNo << " has been added." << endl;
		sizeFlightArr++;
	}
	else {
		if (sameFlight(flightNo)) {
				cout << "Flight " << flightNo << " already exists." << endl;
		}
		else {
		//if flight is unique create new flightArr and add the new flight to it
			Flight* temp = flightArr;
			flightArr = new Flight[sizeFlightArr +1];
			for (int i = 0; i < sizeFlightArr; i++) {
				flightArr[i].setFlightNum(temp[i].getFlightNum());
				flightArr[i].setSeatRow(temp[i].getSeatRow());
				flightArr[i].setSeatCol(temp[i].getSeatCol());
				flightArr[i].initializeSeats(temp[i].getSeatRow(), temp[i].getSeatCol());
			}
			flightArr[sizeFlightArr].setFlightNum(flightNo);
			flightArr[sizeFlightArr].setSeatRow(rowNo);
			flightArr[sizeFlightArr].setSeatCol(seatNo);
			flightArr[sizeFlightArr].initializeSeats(rowNo, seatNo);
			flightArr[sizeFlightArr].setNumOfPassengers(0);
			cout << "Flight " << flightNo << " has been added." << endl;
			sizeFlightArr++;
			if (sizeFlightArr == 2) {
				delete temp;
			}
			else
			delete[] temp;
		}
	}
}

//cancels the specific flight with flightNo
void ReservationSystem::cancelFlight(const int flightNo) {
	if (!sameFlight(flightNo)) {
		cout << "Flight " << flightNo << " does not exist." << endl;
		cout << endl;
	}
	else {
		deleteFlight(flightNo);
		deleteReservation(flightNo);
		cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;
		cout << endl;
	}
}

//shows all flights with their flightNo and available seats num
void ReservationSystem::showAllFlights() {
	if (flightArr == NULL) {
		cout << endl;
		cout << "No flights exist." << endl;
		cout << endl;
	}
	else{
		cout << endl;
		cout << "Flights currently operated :" << endl;
		cout << endl;
		for (int i = 0; i < sizeFlightArr; i++) {
			cout << "Flight " << flightArr[i].getFlightNum() << " (" << flightArr[i].getNumOfAvalaibleSeats() << " available seats )" << endl;
		}
		cout << endl;
	}
}

//
void ReservationSystem::showFlight(const int flightNo) {
	if (!sameFlight(flightNo)) {
		cout << "There is no such flight." << endl;
		cout << endl;
	}
	else {
		cout << "Flight " << flightNo << " has " << getFlight(flightNo)->getNumOfAvalaibleSeats() << " available seats" << endl;
		getFlight(flightNo)->showSeatCondition();
		cout << endl;
	}
}

//makes reservation and creates a reservationCode then returns it
int ReservationSystem::makeReservation(const int flightNo, const int numPassengers,
  	const int* seatRow, const char* seatCol) {
		if (!sameFlight(flightNo)) {
			cout << "Flight " << flightNo << " does not exist." << endl;
			return -1;
		}
		else
		{
			if (!areSeatsEmpty(flightNo, seatRow, seatCol, numPassengers)) {			
			//	3A is not available
				cout << "Reservation can not be made, ";
				for (int i = 0; i < indexesSize; i++) {					
					cout << seatRow[indexes[i]] << seatCol[indexes[i]] << " ";
				}
				if(indexesSize == 1)
				cout << "is not avalaible." << endl;
				else
					cout << "are not avalaible." << endl;
				return -1;
			}
			else {
				if (reservationArr == NULL) {
					reservationArr = new Reservation(reservationCode, numPassengers, flightNo, seatRow, seatCol);
					//changes allocated seats condition from 0(no reserved) to 1(reserved) in seats array
					for (int i = 0; i < numPassengers; i++) {
						getFlight(flightNo)->getSeats()[seatRow[i] - 1][charArrToIntArr(seatCol, numPassengers)[i] - 1] = 1;
					}
					getFlight(flightNo)->addNumPassengers(numPassengers);
					totalReservations++;
					reservationCode++;
				}
				else {
					Reservation* temp = reservationArr;
					reservationArr = new Reservation[totalReservations + 1];
					for (int i = 0; i < totalReservations; i++) {
						reservationArr[i] = temp[i];
					}
					reservationArr[totalReservations].setReservationCode(reservationCode);
					reservationArr[totalReservations].setNumPassengers(numPassengers);
					reservationArr[totalReservations].setFlightNo(flightNo);
					reservationArr[totalReservations].setSeatRow(seatRow);
					reservationArr[totalReservations].setSeatCol(seatCol);
					//changes allocated seats condition from 0(no reserved) to 1(reserved) in seats array
					for (int i = 0; i < numPassengers; i++) {
						(getFlight(flightNo))->getSeats()[seatRow[i] - 1][charArrToIntArr(seatCol, numPassengers)[i] - 1] = 1;
					}
					getFlight(flightNo)->addNumPassengers(numPassengers);
					totalReservations++;
					reservationCode++;
					if (totalReservations == 2) {
						delete temp;
					}
					else
						delete[] temp;
				}				
			}
		}
		return reservationCode - 1;
		cout << endl;
}

//cancels reservation by deleting reservaiton from reservationArr and setting allocated seats from 1 to 0
void ReservationSystem::cancelReservation(const int resCode) {
	if (!sameReservation(resCode)) {
		cout << "No reservations are found under code " << resCode << endl;
		cout << endl;
	}
	else {
		Reservation reservation = *getReservation(resCode);
		for (int i = 0; i < reservation.getNumPassengers(); i++) {
			getFlight(reservation.getFlightNo())->getSeats()[reservation.getSeatRow()[i] - 1][charArrToIntArr(reservation.getSeatCol(), reservation.getNumPassengers())[i] - 1] = 0;
		}
		cout << "Reservation for the seats ";
		for (int i = 0; i < reservation.getNumPassengers(); i++) {
			cout << reservation.getSeatRow()[i] << reservation.getSeatCol()[i] << " ";
		}
		cout << "is canceled in Flight " << reservation.getFlightNo();
		deleteReservation(reservation.getFlightNo());
		cout << endl;
		getFlight(reservation.getFlightNo())->addNumPassengers(-reservation.getNumPassengers());
	}
}

void ReservationSystem::showReservation(const int resCode) {
	
	if (!sameReservation(resCode)) {
		cout << "No reservations are found under code " << resCode << endl;
		cout << endl;
	}
	else {
		Reservation reservation = *getReservation(resCode);
		cout << "Reservations under " << resCode << " in Flight " << reservation.getFlightNo() << ": " ;
		for (int i = 0; i < reservation.getNumPassengers(); i++) {
			cout << reservation.getSeatRow()[i] << reservation.getSeatCol()[i] << " ";
		}
		cout << endl;
	}
}

//returns a bool value for if the flight is in the flightArr
bool ReservationSystem::sameFlight(int flightNo) {
	bool output = false;
	for (int i = 0; i < sizeFlightArr; i++) {
		if (flightArr[i].getFlightNum() == flightNo) {
			output = true;
			return output;
		}
	}
	return output;
}

// gets the flight from flightArr
Flight* ReservationSystem::getFlight(int flightNo) {
	Flight* flight = NULL;
	for (int i = 0; i < sizeFlightArr; i++) {
		if (flightArr[i].getFlightNum() == flightNo) {
			flight = &flightArr[i];
		}
	}
	return flight;
}

// returns the equivalent int array for char array
int* ReservationSystem::charArrToIntArr(const char* seatCol, const int numPassengers) {
	bool control = false;
	if (intArrForColumns != NULL) {
		control = true;
	}
		int* temp = intArrForColumns;

	intArrForColumns = new int[numPassengers];
	for (int i = 0; i < numPassengers; i++) {
		intArrForColumns[i] = seatCol[i] - 'A' + 1;
	}
	if (control) {
		delete[] temp;
	}
	else
		delete temp;
	return intArrForColumns;
}

//returns bool value according to seats condition(given seats are empty or not?) and renew the indexes to print the seats are not empty in the makeReservation
bool ReservationSystem::areSeatsEmpty(const int flightNo, const int* seatRow, const char* seatCol, const int numPassengers) {
	bool result = true;
	bool isNull = true;
	int* temp = NULL;
	int numOfIndexes = 0;
	int* intSeatCol = charArrToIntArr(seatCol, numPassengers);
	int** seatsArr = getFlight(flightNo)->getSeats();
	for (int i = 0; i < numPassengers; i++) {
		if (seatsArr[seatRow[i] - 1][intSeatCol[i] - 1] != 0) {		
			result = false;
			numOfIndexes++;
		}
	}
	indexesSize = numOfIndexes;
	if (indexes == NULL) {
		indexes = new int[numOfIndexes];
	}
	else {
		temp = indexes;
		indexes = new int[numOfIndexes];
		isNull = false;
	}
	numOfIndexes = 0;
	for (int i = 0; i < numPassengers; i++) {
		if (seatsArr[seatRow[i] - 1][intSeatCol[i] - 1] != 0) {
			indexes[numOfIndexes++] = i;
		}
	}
	if(!isNull)
	delete[] temp;
	return result;
}

// deletes the flight with specific no from flightArr
void ReservationSystem::deleteFlight(int flightNo) {
	Flight* temp = flightArr;
	flightArr = new Flight[sizeFlightArr - 1];
	int index = 0;
	for (int i = 0; i < sizeFlightArr; i++) {
		if (temp[i].getFlightNum() != flightNo) {
			flightArr[i] = temp[i];
			index++;
		}
		else
			break;
	}
	for (int i = index+1; i < sizeFlightArr; i++) {
		flightArr[i-1] = temp[i];
	}
	sizeFlightArr--;
	delete[] temp;
}

//delete the reservations with flightNo from reservationArr
void ReservationSystem::deleteReservation(int flightNo) {
	Reservation* temp = reservationArr;
	int indexes = 0;
	int index = 0;
	for (int i = 0; i < totalReservations; i++) {
		if (reservationArr[i].getFlightNo() == flightNo) {
			indexes++;
		}
	}
	reservationArr = new Reservation[totalReservations - indexes];
	for (int i = 0; i < totalReservations; i++) {
		if (temp[i].getFlightNo() != flightNo) {
			reservationArr[index++] = temp[i];
		}
	}
	totalReservations = totalReservations - indexes;
	delete[] temp;
}

// returns a bool value to controll if there is a reservation with resCode
bool ReservationSystem::sameReservation(const int resCode) {
	for (int i = 0; i < totalReservations; i++) {
		if (reservationArr[i].getReservationCode() == resCode) {
			return true;
		}
	}
	return false;
}

//gets reservation with specific resCode
Reservation* ReservationSystem::getReservation(int resCode) {
	Reservation* reservation = NULL;
	for (int i = 0; i < totalReservations; i++) {
		if (reservationArr[i].getReservationCode() == resCode) {
			reservation = &reservationArr[i];
		}
	}
	return reservation;
}
