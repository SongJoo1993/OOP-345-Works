/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-02-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UNIQUEQUEUE_H_
#define	SDDS_UNIQUEQUEUE_H_
#include <cmath>
#include "Queue.h"


namespace sdds {
	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
		unsigned u_count{};
	public:
		bool push(const T& item);

	};

	//Template Member Function Definition
	template<typename T>
	bool UniqueQueue<T>::push(const T& item)
	{
		T temp = item;
		bool isAdded{};
		bool existed{};
		unsigned i{};

		if (Queue<T, 100>::size() == i) {
			Queue<T, 100>::push(temp);
			isAdded = true;
		}
		else {
			for (i = 0; existed == false && i < Queue<T, 100>::size(); i++) {
				if (this->t_element[i] == temp) {
					existed = true;
				}
			}
			if (!existed) {
				Queue<T, 100>::push(temp);
				isAdded = true;
			}
		}
		return isAdded;
	}

	template<>
	bool UniqueQueue<double>::push(const double& item)
	{
		float temp = item;
		bool isAdded{};
		bool existed{};
		unsigned i{};

		if (this->size() == i) {
			Queue<double, 100>::push(temp);
			isAdded = true;
		}
		else {
			for (i = 0; existed == false && i < this->size(); i++) {
				if (fabs(this->t_element[i] - temp) <= 0.005) {
					existed = true;
				}
			}
			if (!existed) {
				Queue<double, 100>::push(temp);
				isAdded = true;
			}
		}
		return isAdded;
	}
}

#endif // !