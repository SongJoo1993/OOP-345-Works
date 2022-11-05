#include <sstream>
#include <string>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"


namespace sdds {
    Vehicle* createInstance(std::istream& in)
    {
        Vehicle* temp{};

        char tag{};
        if (in.good()) {
            in >> tag;
            in.ignore();
            
            if (tag == 'c' || tag == 'C') {
                temp = new sdds::Car(in);
            }
            else if (tag == 'v' || tag == 'V') {
                temp = new sdds::Van(in);
            }
        }

        return temp;
    }
}

