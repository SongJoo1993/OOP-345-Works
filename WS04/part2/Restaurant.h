/*
  File Name: Restaurant.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-09-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

#include <iostream>

namespace sdds {
	class Restaurant { //Composition to Rservation class
		Reservation** r_resevations{};
		size_t noOfReserv{};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Reservation&);
		Restaurant& operator=(const Reservation&);
		~Restaurant();
		size_t size();
		//member functions
		//1. Insertion operator
		friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& rop);
	};
}

#endif // !SDDS_RESTAURANT_H