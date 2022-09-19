/*
  File Name: carads.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-17-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include <fstream>
#include "carads.h"

double g_taxrate;
double g_discount;

namespace sdds {
	Cars::Cars()
	{
	}
	void Cars::read(std::istream& is)
	{
		if (is.good()) {
			is >> c_status;
			is.ignore();
			is.getline(c_brand, 10, ',');
			is.getline(c_model, 15, ',');
			is >> c_manufactureYear;
			is.ignore();
			is >> c_price;
			is.ignore();
			is.get() == 'Y' ? c_onPromo = true : c_onPromo = false;
		}
	}
	void Cars::display(bool reset) const
	{
		static int counter;
		
		if (reset) {
			counter = 0;
		}

		if (c_brand[0]) {
			counter++;
			std::cout.setf(std::ios::left);
			std::cout.width(2);
			std::cout << counter << ". ";
			std::cout.width(10);
			std::cout << c_brand;
			std::cout << "| ";
			std::cout.width(15);
			std::cout << c_model;
			std::cout << "| ";
			std::cout.width(4);
			std::cout << c_manufactureYear;
			std::cout << " |";
			std::cout.unsetf(std::ios::left);
			std::cout.setf(std::ios::fixed);
			std::cout.width(12);
			std::cout.precision(2);
			std::cout << c_price + (c_price * g_taxrate);
			std::cout << "|";
			if (c_onPromo) {
				std::cout.width(12);
				std::cout << (c_price - (c_price * g_discount)) + ((c_price - (c_price * g_discount)) * g_taxrate);
			}
			std::cout << std::endl;
		}
		else if (c_brand[0] && c_manufactureYear == 0) {
			std::cout << counter << ". No Car" << std::endl;
		}
	}
	char Cars::getStatus()
	{
		return c_status;
	}
	void listArgs(int argc, char* argv[])
	{
		int i;
		std::cout << "Command Line:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (i = 0; i < argc; i++) {
			std::cout << "  " << i+1 << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------" << std::endl << std::endl;
	}
}