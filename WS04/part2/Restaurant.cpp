/*
  File Name: Restaurant.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-11-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Restaurant.h"


namespace sdds {

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		unsigned i = 0;
		r_reservations = new Reservation* [cnt];
		
		for (i = 0; i < cnt; i++) {
			r_reservations[i] = new Reservation(*reservations[i]);
		}
		noOfReserv = cnt;
	}

	Restaurant::Restaurant(const Restaurant& src)
	{
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src) {
			for (int i = 0; i < noOfReserv; i++) {
				delete r_reservations[i];
			}
			delete[] r_reservations;

			r_reservations = new Reservation * [src.noOfReserv];

			for (int i = 0; i < src.noOfReserv; i++) {
				r_reservations[i] = new Reservation(*src.r_reservations[i]);
			}
			noOfReserv = src.noOfReserv;
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src) {
			for (int i = 0; i < noOfReserv; i++) {
				delete r_reservations[i];
			}
			delete[] r_reservations;

			noOfReserv = src.noOfReserv;
			src.noOfReserv = 0;
			r_reservations = src.r_reservations;

			src.r_reservations = nullptr;
		}

		return *this;
	}

	Restaurant::~Restaurant()
	{
		for (int i = 0; i < noOfReserv; i++) {
			delete r_reservations[i];
		}
		delete[] r_reservations;
	}

	size_t Restaurant::size()
	{
		return noOfReserv;
	}

	std::ostream& operator<<(std::ostream& ostr, const Restaurant& rop)
	{
		static unsigned CALL_CNT{};
		CALL_CNT++;
		if (rop.noOfReserv) {
			ostr << "--------------------------" << std::endl;
			ostr << "Fancy Restaurant (" << CALL_CNT << ")" << std::endl;
			ostr << "--------------------------" << std::endl;
			for (int i = 0; i < rop.noOfReserv; ++i)
			{
				std::cout << *(rop.r_reservations[i]);
			}
			ostr << "--------------------------" << std::endl;
		}
		else {
			ostr << "--------------------------" << std::endl;
			ostr << "Fancy Restaurant (" << CALL_CNT << ")" << std::endl;
			ostr << "--------------------------" << std::endl;
			ostr << "This restaurant is empty!" << std::endl;
			ostr << "--------------------------" << std::endl;
		}
		return ostr;
	}
}
