#include <string>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& istr)
	{
		if (!istr.fail()) {

		}
	}

	std::string Car::condition() const
	{
		return std::string();
	}

	double Car::topSpeed() const
	{
		return 0.0;
	}

	void Car::display(std::ostream&) const
	{
	}

}