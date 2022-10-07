/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-09-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds
{
	class Reservation {
		char* r_id{};
		std::string r_name{};
		std::string r_email{};
		int r_peopleNum{};
		int r_day{};
		int r_hour{};
	public:
		Reservation() {};
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& ostr, const Reservation& rop);
		std::string getCharArray(std::string res, char* &des);
		std::string getString(std::string res, std::string &des);
		std::string getInt(std::string res, int &des);
	};
	std::string trim(std::string &res); // removing whitespace
}

#endif // !SDDS_RESERVATION_H
