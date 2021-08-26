ReservationSystem: ReservationSystem.o main.o Flight.o Flight.o Reservation.o
	g++ ReservationSystem.o main.o Flight.o Reservation.o -o ReservationSystem

ReservationSystem.o: ReservationSystem.cpp
	g++ -c ReservationSystem.cpp
	
Flight.o:Flight.cpp
	g++ -c Flight.cpp

Reservation.o:Reservation.cpp
	g++ -c Reservation.cpp

main.o:main.cpp
	g++ -c main.cpp

remove:
	rm -f ReservationSystem.o main.o Flight.o Reservation.o ReservationSystem

removeOnlyBinary:
	rm -f ReservationSystem.o main.o Flight.o Reservation.o