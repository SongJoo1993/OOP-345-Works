#include "CrimeStatistics.h"
#include<algorithm>

namespace sdds {
	CrimeStatistics::CrimeStatistics(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			return;
		}
		
		while (file)
		{
			c_crimes.push_back(read(file));
		}
	}

	void CrimeStatistics::display(std::ostream& out) const
	{
		for_each(c_crimes.begin(), c_crimes.end(), [](Crime singleLine) {std::cout << singleLine; });
	}

	Crime CrimeStatistics::read(std::istream& istr)
	{
		Crime temp{};
		std::string line;
		std::string tempLine;
		if (istr.good()) {
			std::getline(istr, line);
			tempLine = getString(line, temp.c_province);
			tempLine = getString(tempLine, temp.c_district);
			tempLine = getString(tempLine, temp.c_crime);
			tempLine = getInt(tempLine, temp.c_year);
			tempLine = getInt(tempLine, temp.c_noOfCases);
			tempLine = getInt(tempLine, temp.c_noOfResolved);

			if (istr.eof()) {
				istr.ignore();
			}
		}
		return temp;
	}

	std::string CrimeStatistics::getString(std::string res, std::string& des)
	{

		std::string idTemp;
		int tabPosition = res.find(' ');
		idTemp = res.substr(0, tabPosition);
		des = idTemp;

		res.erase(0, tabPosition + 1);
		trim(res);

		return res;
	}

	std::string CrimeStatistics::getInt(std::string res, unsigned& des)
	{
		std::string idTemp;
		//unsigned spacePosition = res.find(' ');
		unsigned spacePosition = res.find(' ') < 100 ? res.find(' ') : res.length() + 1;
		idTemp = res.substr(0, spacePosition);
		des = stoi(idTemp);

		res.erase(0, spacePosition + 1);
		trim(res);

		return res;
	}

	void trim(std::string& res)
	{
		std::string whitespaces(" \t");
		res.erase(0, res.find_first_not_of(whitespaces));
	}

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| ";
		out.width(21);
		out << std::left << theCrime.c_province;
		out << " | ";
		out.width(15);
		out << theCrime.c_district;
		out << " | ";
		out.width(20);
		out << theCrime.c_crime;
		out << " | ";
		out.width(6);
		out << std::right << theCrime.c_year;
		out << " | ";
		out.width(4);
		out << theCrime.c_noOfCases;
		out << " | ";
		out.width(3);
		out << theCrime.c_noOfResolved;
		out << " |";
		out << std::endl;
		return out;
	}
}