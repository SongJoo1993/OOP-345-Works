#include <sstream>
#include <string>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"


namespace sdds {
    Vehicle* sdds::createInstance(std::istream& in)
    {
        Vehicle* temp{};
        char tag{};
        if (in.good()) {
            in >> tag;
            in.ignore();
        }

        if (tag == 'c' || tag == 'C') {
            temp = new sdds::Car(in);
        }
        else if (tag == 'f' || tag == 'F') {
            temp = new sdds::Van(in);
        }
        return temp;
    }
}

