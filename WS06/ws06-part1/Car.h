#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	enum CarCondition { newCondiiton, usedCondiiton, brokenCondiiton };

	class Car : public Vehicle {
		std::string c_maker;
		CarCondition c_conditions;
		int c_topSpeed;
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
	};
}

#endif