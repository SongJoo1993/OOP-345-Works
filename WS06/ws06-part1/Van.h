#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	enum Type { pickup, minibus, camper };
	enum Purpose { delivery, passenger, camping };
	enum VanCondition { newVan, usedVan, brokenVan };

	class Van : public Vehicle {
		std::string v_maker;
		Type v_type{};
		Purpose v_purpose{};
		VanCondition v_conditions;
		int v_topSpeed{};
	public:
		Van(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream&) const;
	};
	void trim(std::string& res);
}

#endif