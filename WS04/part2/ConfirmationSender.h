/*
  File Name: ConfirmationSender.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-09-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

#include <iostream>

namespace sdds {
	class ConfirmationSender {
		const sdds::Reservation** c_reservations{};
	public:
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& rop);
	};
}

#endif // !SDDS_CONFIRMATIONSENDER_H