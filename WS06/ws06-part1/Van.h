#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	enum Type { pickup, minibus, camper };
	enum VanCondition { newCondiiton, usedCondiiton, brokenCondiiton };
	enum Purpose { delivery, passenger, camping };

	class Van : public Vehicle {
		std::string v_maker;
		Type c_type;
		VanCondition c_conditions;
		int v_topSpeed;
	public:
		Van(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
	};
}

#endif