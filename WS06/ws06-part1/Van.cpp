#include "Van.h"


namespace sdds {
	Van::Van(std::istream&)
	{
	}

	std::string Van::condition() const
	{
		return std::string();
	}

	double Van::topSpeed() const
	{
		return 0.0;
	}

	void Van::display(std::ostream&) const
	{
	}

}