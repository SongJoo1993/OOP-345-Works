#include <string>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& istr)
	{
		char condition{};
		if (istr.good()) {
			std::getline(istr, c_maker, ',');
			trim(c_maker);
			istr >> condition;
			if (condition == 'n') {
				c_conditions = newCar;
			}
			else if (condition == 'u') {
				c_conditions = usedCar;
			}
			else if (condition == 'b') {
				c_conditions = brokenCar;
			}
			istr.ignore();
			istr >> c_topSpeed;
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
		ostr << " |" << std::endl;
	}
	void trim(std::string& res)
	{
		std::string whitespaces(" \t");
		res.erase(res.find_last_not_of(whitespaces) + 1);
		res.erase(0, res.find_first_not_of(whitespaces));
	}
}