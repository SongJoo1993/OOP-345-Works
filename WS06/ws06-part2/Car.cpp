/*
  File Name: Car.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include <string>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& istr)
	{
		std::string condition{};
		if (istr.good()) {
			std::getline(istr, c_maker, ',');
			trim(c_maker);

			std::getline(istr, condition, ',');
			trim(condition);

			if (condition == "n" || condition.empty()) {
				c_conditions = newCar;
			}
			else if (condition == "u") {
				c_conditions = usedCar;
			}
			else if (condition == "b") {
				c_conditions = brokenCar;
			}
			else {
				throw "Invalid record!";
			}

			istr >> c_topSpeed;
			if (istr.fail()) {
				throw "Invalid record!";
			}
			istr.ignore();
		}
	}

	std::string Car::condition() const
	{
		std::string condition{};
		if (c_conditions == CarCondition::newCar) {
			condition = "new";
		} else if (c_conditions == CarCondition::usedCar) {
			condition = "used";
		} else if (c_conditions == CarCondition::brokenCar) {
			condition = "broken";
		}
		return condition;
	}

	double Car::topSpeed() const
	{
		return c_topSpeed;
	}

	void Car::display(std::ostream& ostr) const
	{
		ostr << "| ";
		ostr.width(10);
		ostr << c_maker;
		ostr << " | ";
		ostr.setf(std::ios::left);
		ostr.width(6);
		ostr << condition();
		ostr.unsetf(std::ios::left);
		ostr << " | ";
		ostr.width(6);
		ostr.setf(std::ios::fixed);
		ostr.precision(2);
		ostr << topSpeed();
		ostr.unsetf(std::ios::fixed);
		ostr << " |";
	}
	void trim(std::string& res)
	{
		std::string whitespaces(" \t");
		res.erase(res.find_last_not_of(whitespaces) + 1);
		res.erase(0, res.find_first_not_of(whitespaces));
	}
}