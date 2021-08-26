#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
using namespace std;

/*
**Name: Arman Engin Sucu
**ID: 21801777
*/

class Reservation;
class Flight;
class ReservationSystem {
public:
	//CONSTRUCTORS
	ReservationSystem();
	~ReservationSystem();
	//METHODS
	void addFlight(const int flightNo, const int rowNo, const int seatNo);
	void cancelFlight(const int flightNo);
	void showAllFlights();
	void showFlight(const int flightNo);
	int makeReservation(const int flightNo, const int numPassengers,
		const int* seatRow, const char* seatCol);
	void cancelReservation(const int resCode);
	void showReservation(const int resCode);
	
private:
	//PROPERTIES
	Flight* flightArr;
	int sizeFlightArr;
	int flightSize;
	Reservation* reservationArr;
	int totalReservations;
	int reservationCode;
	int* intArrForColumns;
	int* indexes;
	int indexesSize;

public:
	//METHODS
	bool sameFlight(int flightNo);
	Flight* getFlight(int flightNo);
	int* charArrToIntArr(const char* seatCol, const int numPassengers);
	bool areSeatsEmpty(const int flightNo, const int* seatRow, const char* seatCol, int const numPassengers);
	void deleteFlight(int flightNo);
	void deleteReservation(int reservationCode);
	bool sameReservation(const int resCode);
	Reservation* getReservation(int resCode);
};
#endif