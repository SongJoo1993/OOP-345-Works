#include "Restaurant.h"
/*
  File Name: Restaurant.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-09-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

namespace sdds {

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		
	}
	Restaurant::Restaurant(const Reservation&)
	{
	}
	Restaurant& Restaurant::operator=(const Reservation&)
	{
		return *this;
	}
	Restaurant::~Restaurant()
	{
	}
	size_t Restaurant::size()
	{
		return size_t();
	}
	std::ostream& operator<<(std::ostream& ostr, const Restaurant& rop)
	{
		return ostr;
	}
}
