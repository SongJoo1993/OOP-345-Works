/*
  File Name: Autoshop.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
			{
				if (test(*it)) {
					vehicles.push_back(*it);
				}
			}
		};
	};
}

#endif