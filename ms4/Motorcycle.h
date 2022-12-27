/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 01 December 2022
*/

#ifndef __SDDS_MOTORCYCLE_H__
#define __SDDS_MOTORCYCLE_H__

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Vehicle.h"

namespace sdds
{
    class Motorcycle : public Vehicle
    {
        bool m_sidecar;
    public:
        Motorcycle();
        Motorcycle(const char* licensePlate, const char* makeModel);
        ~Motorcycle();
        Motorcycle(const Motorcycle& src);
        Motorcycle& operator=(const Motorcycle& src);
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& writeType(std::ostream& ostr = std::cout) const;
    };
}

#endif