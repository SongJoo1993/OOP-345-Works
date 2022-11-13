#ifndef SDDS_CrimeStatistics_H
#define SDDS_CrimeStatistics_H

#include <iostream>
#include <fstream>
#include<string>
#include <vector>

namespace sdds {
	enum CrimeTypes {Assault, Robbery, Extortion, Fraud };

	struct Crime {
		std::string c_province{};
		std::string c_district{};
		/*CrimeTypes c_crime{};*/
		std::string c_crime{};
		unsigned c_year{};
		unsigned c_noOfCases{};
		unsigned c_noOfResolved{};
	};

	class CrimeStatistics {
		std::vector<Crime> c_crimes;
	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const; 
		Crime read(std::istream&);
		std::string getString(std::string res, std::string& des);
		std::string getInt(std::string res, unsigned& des);
	};

	void trim(std::string& res);
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif // !SDDS_CrimeStatistics_H
