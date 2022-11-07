/*
  File Name: Luxuryvan.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include "Van.h"

namespace sdds {
	class Luxuryvan : public Van {
		std::string m_consumption{};
	public:
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}

#endif