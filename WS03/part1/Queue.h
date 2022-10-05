/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-29-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_QUEUE_H_
#define	SDDS_QUEUE_H_
#include "Dictionary.h"

namespace sdds
{
	template<typename T, unsigned CAPACITY>
	class Queue
	{
		T t_element[CAPACITY]{};
		unsigned t_count{};
		static T t_dummy;
		
	public:
		Queue(){}
		bool push(const T& item);
		T& pop();
		unsigned size();
		/*std::ostream& display(std::ostream& os = std::cout);*/
		void display(std::ostream& os = std::cout);
		const T operator[](unsigned i)const;
		~Queue() {}
	};

	template <typename T, unsigned CAPACITY>
	T Queue<T, CAPACITY>::t_dummy{};

	template <>
	Dictionary Queue<Dictionary, 100u>::t_dummy = Dictionary("Empty Term", "Empty Substitute");

	template<typename T, unsigned CAPACITY>
	bool Queue<T, CAPACITY>::push(const T& item)
	{
		T temp = item;
		bool isAdded{};

		if (t_count <= CAPACITY) {
			this->t_element[t_count++] = temp;
			isAdded = true;
		}
		return isAdded;
	}

	template <typename T, unsigned CAPACITY>
	T& Queue<T, CAPACITY>::pop()
	{
		T cpy = t_count > 0 ? t_element[0] : 0;
		
		for (unsigned i = 0; i < t_count; i++) t_element[i] = t_element[i + 1];
		t_element[t_count - 1] = 0;

		return cpy;
	}

	template <typename T, unsigned CAPACITY>
	unsigned Queue<T, CAPACITY>::size()
	{
		return t_count;

	}

	//template <typename T, unsigned CAPACITY>
	//std::ostream& Queue<T, CAPACITY>::display(std::ostream& os)
	//{
	//	std::cout << "----------------------" << std::endl;
	//	std::cout << "| Dictionary Content |" << std::endl;
	//	std::cout << "----------------------" << std::endl;
	//	
	//	for (int i = 0; i < t_count; i++)
	//	{
	//		os << t_element[i] << std::endl;
	//	}
	//	return os;
	//}

	template <typename T, unsigned CAPACITY>
	void Queue<T, CAPACITY>::display(std::ostream& os)
	{
		std::cout << "----------------------" << std::endl;
		std::cout << "| Dictionary Content |" << std::endl;
		std::cout << "----------------------" << std::endl;

		for (unsigned i = 0; i < t_count; i++)
		{
			os << t_element[i] << std::endl;
		}
		std::cout << "----------------------" << std::endl;
	}

	template <typename T, unsigned CAPACITY>
	const T Queue<T, CAPACITY>::operator[](unsigned i) const
	{
		T temp{};

		if (i < CAPACITY) {
			temp = t_element[i];
		}
		else {
			temp = t_dummy;
		}


		return temp;

	}
}

#endif // !
