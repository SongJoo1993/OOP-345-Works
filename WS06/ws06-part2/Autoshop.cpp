/*
  File Name: Autoshop.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Autoshop.h"

namespace sdds{

    Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);

        return *this;
    }

    void sdds::Autoshop::display(std::ostream& out) const
    {
        for (auto& car : m_vehicles)
        {
            car->display(out);
            out << std::endl;
        }
    }
    Autoshop::~Autoshop()
    {
        for (auto& v : m_vehicles)
            delete v;
    }
}

