/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-09-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <fstream>
#include <string.h>
#include <string>
#include "Reservation.h"

namespace sdds
{
	void Reservation::update(int day, int time)
	{   
		r_day = day;
		r_hour = time;
	}

	Reservation::Reservation(const std::string& res)
	{
		std::string resStr;
		resStr = getCharArray(res, r_id);
		resStr = getString(resStr, r_name);
		resStr = getString(resStr, r_email);
		resStr = getInt(resStr, r_peopleNum);
		resStr = getInt(resStr, r_day);
		resStr = getInt(resStr, r_hour);
	}

	std::ostream& operator<<(std::ostream& ostr, const Reservation& rop)
	{
		return ostr;
	}


	std::string Reservation::getCharArray(std::string res, char* &des)
	{
		std::string idTemp;
		int colonPosition = res.find(':');
		idTemp = res.substr(0, colonPosition);
		des = new char[idTemp.length() + 1];

		for (int i = 0; i < idTemp.length(); i++) des[i] = idTemp[i];
		des[idTemp.length()] = '\0';

		res.erase(0, colonPosition + 1);
		trim(res);

		return res;
	}
	std::string Reservation::getString(std::string res, std::string& des)
	{
		std::string idTemp;
		int colonPosition = res.find(',');
		idTemp = res.substr(0, colonPosition);
		trim(idTemp);
		des = idTemp;

		res.erase(0, colonPosition + 1);
		trim(res);

		return res;
	}
	std::string Reservation::getInt(std::string res, int& des)
	{
		// Fix colonPosition to cut up to comma
		std::string idTemp;
		int colonPosition = res.find(',') == 1 ? 2 : res.find(',');
		idTemp = res.substr(0, colonPosition - 1);
		des = stoi(idTemp);

		colonPosition == 1 ? colonPosition++ : colonPosition;
		
		res.erase(0, colonPosition < 2 ? colonPosition : colonPosition + 1);
		trim(res);

		return res;
	}

	std::string trim(std::string& res)
	{
		std::string whitespaces(" \t");
		res.erase(res.find_last_not_of(whitespaces) + 1);
		res.erase(0, res.find_first_not_of(whitespaces));
		return res;
	}
}

