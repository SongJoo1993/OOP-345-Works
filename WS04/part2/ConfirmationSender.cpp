/*
  File Name: ConfirmationSender.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-11-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src) {
			c_nums = src.c_nums;
			delete[] c_reservations;
			c_reservations = new const Reservation * [c_nums];
			for (unsigned i = 0; i < c_nums; i++) c_reservations[i] = src.c_reservations[i];
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
	{
		if (this != &src) {
			c_nums = src.c_nums;
			delete[] c_reservations;
			c_reservations = src.c_reservations;
			src.c_nums = 0;
			src.c_reservations = nullptr;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] c_reservations;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool existed{};

		for (unsigned i = 0; i < c_nums && !existed; i++) {
			if (c_reservations[i] == &res) existed = true;
		}
		
		if (!existed) {
			const Reservation** temp{};
			temp = new const sdds::Reservation * [c_nums + 1];
			for (unsigned i = 0; i < c_nums; i++) temp[i] = c_reservations[i];
			temp[c_nums++] = &res;
			delete[] c_reservations;
			c_reservations = temp;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool found{};
		bool changed{};

		for (unsigned i = 0; i < c_nums && !found; i++) {
			if (c_reservations[i] == &res) {
				c_reservations[i] = nullptr;
				found = true;
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& rop)
	{

		if (rop.c_nums) {
			ostr << "--------------------------" << std::endl;
			ostr << "Confirmations to Send" << std::endl;
			ostr << "--------------------------" << std::endl;
			for (int i = 0; i < rop.c_nums; ++i)
			{
				if ((rop.c_reservations[i]) != nullptr) {
					std::cout << *(rop.c_reservations[i]);
				}
			}
			ostr << "--------------------------" << std::endl;
		}
		else {
			ostr << "--------------------------" << std::endl;
			ostr << "Confirmations to Send" << std::endl;
			ostr << "--------------------------" << std::endl;
			ostr << "There are no confirmations to send!" << std::endl;
			ostr << "--------------------------" << std::endl;
		}
		return ostr;
	}
}