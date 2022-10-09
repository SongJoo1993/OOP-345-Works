#include "ConfirmationSender.h"
/*
  File Name: ConfirmationSender.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-09-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

namespace sdds {
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& rop)
	{
		return ostr;
	}


}