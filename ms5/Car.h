
/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 09 December 2022
*/

#ifndef __SDDS_CAR_H__
#define __SDDS_CAR_H__

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Vehicle.h"

namespace sdds
{
    class Car : public Vehicle
    {
        bool m_carWash;
    public:

        Car();
        Car(const char* licensePlate, const char* makeModel);
        ~Car();
        Car(const Car& src);
        Car& operator=(const Car& src);
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& writeType(std::ostream& ostr = std::cout) const;
    };
}

#endif