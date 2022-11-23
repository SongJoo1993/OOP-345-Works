/*
  File Name: Autoshop.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-22-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool sinValidation(std::string input)
		{
			size_t eachDigit = 0;
			size_t sum = 0;
			size_t length = input.length();
			size_t i{};

			for (i = 0; i < length; i++)
			{
				eachDigit = input[i] - '0';
				if (i % 2 != 0)
				{
					eachDigit *= 2;
					if (eachDigit > 9)
					{
						eachDigit -= 9;
					}
				}
				sum += eachDigit;
			}
			return sum % 10 == 0;
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const std::unique_ptr<T>& smartPointer)
		{
			list.push_back(*smartPointer);
		}
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* rawPointer)
		{
			list.push_back(*rawPointer);
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
