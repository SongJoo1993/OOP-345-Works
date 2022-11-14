#include "CrimeStatistics.h"
#include <iomanip>
#include<algorithm>
#include<numeric>

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
		int totalCases{}, totalResolvedCases{};

		for_each(c_crimes.begin(), c_crimes.end(), [&](Crime singleLine) 
			{
			std::cout << singleLine << std::endl; 
			totalCases += singleLine.c_noOfCases;
			totalResolvedCases += singleLine.m_resolved;
			});

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::setw(78)	<< "Total Crimes:";
		out << std::setw(7) << totalCases << " |" << std::endl;
		out << "|" << std::setw(78) << "Total Resolved Cases:";
		out << std::setw(7) << totalResolvedCases << " |" << std::endl;
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
			tempLine = getInt(tempLine, temp.m_resolved);

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

	std::string CrimeStatistics::getInt(std::string res, int& des)
	{
		std::string idTemp;
		unsigned spacePosition = res.find(' ') < 100 ? res.find(' ') : res.length() + 1;
		idTemp = res.substr(0, spacePosition);
		des = stoi(idTemp);

		res.erase(0, spacePosition + 1);
		trim(res);

		return res;
	}

	void CrimeStatistics::sort(std::string fieldName)
	{
		if (fieldName == "Province") {
			std::sort(this->c_crimes.begin(), this->c_crimes.end(), [](Crime& first, Crime& second){ 
				return first.c_province < second.c_province; 
			});
		}
		else if (fieldName == "Crime") {
			std::sort(this->c_crimes.begin(), this->c_crimes.end(), [](Crime& first, Crime& second) {
				return first.c_crime < second.c_crime;
			});
		}
		else if (fieldName == "Cases") {
			std::sort(this->c_crimes.begin(), this->c_crimes.end(), [](Crime& first, Crime& second) {
				return first.c_noOfCases < second.c_noOfCases;
			});
		}
		else if (fieldName == "Resolved") {
			std::sort(this->c_crimes.begin(), this->c_crimes.end(), [](Crime& first, Crime& second) {
				return first.m_resolved < second.m_resolved;
			});
		}
	}

	void CrimeStatistics::cleanList()
	{
		Crime temp;
		std::replace_if(this->c_crimes.begin(), this->c_crimes.end(),
			[&temp](const Crime& each) {
				temp = each;
				temp.c_crime = "";
				return each.c_crime == "[None]";
			}, temp);
	}

	bool CrimeStatistics::inCollection(std::string crimeType) const
	{
		return std::any_of(this->c_crimes.begin(), this->c_crimes.end(), 
			[&](Crime each) {
				return each.c_crime.compare(crimeType);
			});
	}

	std::list<Crime> CrimeStatistics::getListForProvince(std::string province) const
	{
		std::list<Crime> temp(this->c_crimes.size());

		std::copy(this->c_crimes.begin(), this->c_crimes.end(), temp.begin());

		temp.erase(
			std::remove_if(std::begin(temp), std::end(temp), [&province](Crime& eachLine)
			{ return eachLine.c_province != province; }),
			std::end(temp)
		);
		return temp;
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
		out << theCrime.m_resolved;
		out << " |";
		return out;
	}
}