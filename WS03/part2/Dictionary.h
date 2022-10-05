/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Oct-02-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_DICTIONARY_H_
#define	SDDS_DICTIONARY_H_
#include <string>

namespace sdds
{
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const {
			return m_term;
		}
		const std::string& getDefinition() const {
			return m_definition;
		}
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
		Dictionary() {};
		std::ostream& display(std::ostream& os)const;
		bool operator==(const Dictionary& src);
	};

	std::ostream& operator<<(std::ostream& os, class Dictionary ro);
}
#endif // !