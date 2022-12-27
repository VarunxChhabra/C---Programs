
/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 09 December 2022
*/

#ifndef __SDDS_PARKING_H__
#define __SDDS_PARKING_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Menu.h"
namespace sdds
{
    const int MAX_PARKING_SPOTS = 100;
    class Parking
    {
        int m_noOfSpots;
        Vehicle* m_parkingSpots[MAX_PARKING_SPOTS];
        int m_noOfParkedVehicles;
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
        Parking(const char* datafile, int noOfSpots);
        ~Parking();
        Parking(const Parking& src) = delete;
        Parking& operator=(const Parking& src) = delete;
        int run();
    };
}

#endif