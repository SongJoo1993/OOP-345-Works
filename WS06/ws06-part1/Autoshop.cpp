#include "Autoshop.h"

namespace sdds{

    Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);

        return *this;
    }

    void sdds::Autoshop::display(std::ostream& out) const
    {
        for (int i = 0; i < m_vehicles.size(); i++) {
            m_vehicles[i]->display(out);
        }
    }
}

