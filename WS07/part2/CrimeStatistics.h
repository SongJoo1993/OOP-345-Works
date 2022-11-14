#ifndef SDDS_CrimeStatistics_H
#define SDDS_CrimeStatistics_H

#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <list>

namespace sdds {
	enum CrimeTypes {Assault, Robbery, Extortion, Fraud };

	struct Crime {
		std::string c_province{};
		std::string c_district{};
		std::string c_crime{};
		int c_year{};
		int c_noOfCases{};
		int m_resolved{};
	};

	class CrimeStatistics {
		std::vector<Crime> c_crimes;
	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const; 
		Crime read(std::istream&);
		std::string getString(std::string res, std::string& des);
		std::string getInt(std::string res, int& des);
		void sort(std::string);
		void cleanList();
		bool inCollection(std::string) const;
		std::list<Crime> getListForProvince(std::string) const;
	};
	void trim(std::string& res);
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif // !SDDS_CrimeStatistics_H
