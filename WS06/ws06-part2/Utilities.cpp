/*
  File Name: Utilities.cpp
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <sstream>
#include <string>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"


namespace sdds {
    Vehicle* createInstance(std::istream& in)
    {
        Vehicle* temp{};

        char tag{};
        if (in.good()) {
            in >> tag;
            in.ignore(100,',');
            
            if (tag == 'c' || tag == 'C') {
                temp = new sdds::Car(in);
            }
            else if (tag == 'v' || tag == 'V') {
                temp = new sdds::Van(in);
            }            
            else if (tag == 'r' || tag == 'R') {
                temp = new sdds::Racecar(in);
            }            
            else if (tag == 'l' || tag == 'L') {
                temp = new sdds::Luxuryvan(in);
            }
            else
            {
                std::string error = "Unrecognized record type: [";
                error += tag;
                error += "]";
                throw error;
            }
        }
        else
        {
            in.ignore();
        }

        return temp;
    }
}

