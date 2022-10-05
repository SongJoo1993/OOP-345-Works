/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-29-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Dictionary.h"
#include <iostream>

namespace sdds
{

	std::ostream& Dictionary::display(std::ostream& os) const
	{
		std::cout.width(20);
		os << m_term;
		os << ": " << m_definition;

		return os;
	}

	std::ostream& operator<<(std::ostream& os, Dictionary& ro)
	{
		ro.display(os);
		return os;
	}
}