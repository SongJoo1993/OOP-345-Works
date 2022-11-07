/*
  File Name: Racecar.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in): Car(in)
	{
		if (in.good()) {
			in >> m_booster;
			in.ignore();
		}
	}

	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}

	double Racecar::topSpeed() const
	{

		return Car::topSpeed() + (Car::topSpeed() * m_booster);
	}

}