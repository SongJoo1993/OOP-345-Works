/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-25-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H_
#define SDDS_TIMER_H_

#include <chrono>
using namespace std;

namespace sdds
{
	class Timer {
		std::chrono::steady_clock::time_point startTime;
		/*std::chrono::time_point<std::chrono::system_clock> now;*/
		long long timeStamp{};
	public:
		void start();
		long long stop();
	};
	
}
#endif // !