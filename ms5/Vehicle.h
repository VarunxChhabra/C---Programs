/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 09 December 2022
*/


#ifndef __SDDS_VEHICLE_H__
#define __SDDS_VEHICLE_H__

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include "ReadWritable.h"

namespace sdds
{
    class Vehicle : public ReadWritable
    {
        char m_licensePlate[9];
        char* m_makeModel;
        int m_parkingSpotNumber;
    protected:
        void setEmpty();
        bool isEmpty() const;
        const char* getLicensePlate() const;
        const char* getMakeModel() const;
        void setMakeModel(const char* makeModel);
    public:
        Vehicle();
        Vehicle(const char* licensePlate, const char* makeModel);
        ~Vehicle();
        Vehicle(const Vehicle& src);
        Vehicle& operator=(const Vehicle& src);
        int getParkingSpot() const;
        void setParkingSpot(int parkingSpot);
        bool operator==(const char* licensePlate) const;
        bool operator==(const Vehicle& src) const;
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        virtual std::ostream& writeType(std::ostream& ostr = std::cout) const = 0;
    };
}

#endif