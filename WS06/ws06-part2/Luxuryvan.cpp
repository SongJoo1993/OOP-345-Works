/*
  File Name: Luxuryvan.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Luxuryvan.h"

namespace sdds {
	Luxuryvan::Luxuryvan(std::istream& in) : Van(in)
	{
		if (in.good()) {
			in >> m_consumption;
			trim(m_consumption);
			if (m_consumption == "g")
			{
				throw "Invalid record!";
			}
			in.ignore();
		}
	}

	void Luxuryvan::display(std::ostream& out) const
	{
		Van::display(out);
		out << " electric van  *";
	}

	std::string Luxuryvan::consumption() const
	{
		return m_consumption;
	}

}