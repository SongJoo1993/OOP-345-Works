/*
  File Name: Reservation.cpp
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
		int emailSpace = 24 - (rop.r_email.length() + 2);
		ostr << "Reservation";
		ostr.width(11);
		ostr << rop.r_id;
		ostr << ":";
		ostr.width(21);
		ostr << rop.r_name;
		ostr << "  ";
		ostr.setf(std::ios::left);
		ostr << "<" << rop.r_email << ">";
		for (int i = 1; i < emailSpace; i++) ostr << " ";
		ostr.unsetf(std::ios::left);
		printKitchen(ostr, rop.r_hour);
		ostr << " on day " << rop.r_day << " @ " << rop.r_hour << ":00 for " << rop.r_peopleNum;
		rop.r_peopleNum == 1 ? ostr << " person." : ostr << " people."; 
		ostr << std::endl;

		return ostr;
	}


	std::string Reservation::getCharArray(std::string res, char* &des)
	{
		std::string idTemp;
		int colonPosition = res.find(':');
		idTemp = res.substr(0, colonPosition);
		trim(idTemp);
		des = new char[idTemp.length() + 1];

		for (unsigned i = 0; i < idTemp.length(); i++) des[i] = idTemp[i];
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
		std::string idTemp;
		/*int colonPosition = res.find(',') == 1 ? 2 : res.find(',');*/
		int colonPosition = res.find(',');
		//colonPosition == -1 ? colonPosition = 1 : colonPosition == 1 ? colonPosition++ : colonPosition;
		colonPosition == -1 ? colonPosition = 1 : colonPosition;
		idTemp = res.substr(0, colonPosition == 1 ? colonPosition + 1 : colonPosition - 1);
		des = stoi(idTemp);

		res.erase(0, colonPosition + 1);
		trim(res);

		return res;
	}

	Reservation::~Reservation()
	{
		delete[] r_id;
	}

	std::string trim(std::string& res)
	{
		std::string whitespaces(" \t");
		res.erase(res.find_last_not_of(whitespaces) + 1);
		res.erase(0, res.find_first_not_of(whitespaces));
		return res;
	}

	std::ostream& printKitchen(std::ostream& ostr, int time)
	{
		if (time >= 6 && time <= 9)
		{
			ostr << " Breakfast";
		}
		else if (time >= 11 && time <= 15)
		{
			ostr << " Lunch";
		}
		else if (time >= 17 && time <= 21)
		{
			ostr << " Dinner";
		}
		else
		{
			ostr << " Drinks";
		}
		return ostr;
	}

}

