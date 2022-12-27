/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 12 November 2022
*/
#ifndef __SDDS_PARKING_H__
#define __SDDS_PARKING_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Menu.h"
namespace sdds
{
    class Parking
    {
        char* m_filename;
        Menu m_parkingMenu;
        Menu m_vehicleMenu;
        bool isEmpty() const;
        void parkingStatus() const;
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicles() const;
        void findVehicle() const;
        bool closeParking();
        bool exitParkingApp() const;
        bool loadDataFile();
        void saveDataFile() const;

    public:
        Parking(const char* filename = nullptr);
        ~Parking();
        Parking(const Parking& src) = delete;
        Parking& operator=(const Parking& src) = delete;
        int run();
    };
}

#endif