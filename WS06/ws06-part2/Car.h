/*
  File Name: Car.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	enum CarCondition { newCar, usedCar, brokenCar };

	class Car : public Vehicle {
		std::string c_maker;
		CarCondition c_conditions;
		int c_topSpeed{};
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
	};
	void trim(std::string& res);
}

#endif