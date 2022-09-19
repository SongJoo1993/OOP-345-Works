/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-17-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CARADS_H_ 
#define SDDS_CARADS_H_

#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	class Cars {
		char* c_brand{};
		char c_model[16]{};
		unsigned c_manufactureYear{};
		double c_price{};
		char c_status{};
		bool c_onPromo{};
	public:
		Cars();
		Cars(const Cars&);
		Cars& operator=(const Cars&);
		~Cars();
		void read(std::istream& is);
		void display(bool reset) const;
		char getStatus();
		operator bool() const;
	};
	void listArgs(int argc, char* argv[]);
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}

#endif // !


