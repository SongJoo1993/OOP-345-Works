/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-25-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include"Timer.h"

namespace sdds {
	void Timer::start()
	{
		startTime = std::chrono::steady_clock::now();
		
	}

	long long Timer::stop()
	{
		auto endTime = std::chrono::steady_clock::now();
		

		std::chrono::duration<long long, std::nano> diff = endTime - startTime;
		

		timeStamp = diff.count();
		

		return timeStamp;
	}

}