/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 10 October 2022
*/
#ifndef __SDDS_TOURBUS_H__
#define __SDDS_TOURBUS_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "TourTicket.h"
namespace sdds
{
    class TourBus
    {
        TourTicket* ticket;
        int noSeats;
        int noTicket;

    public:
        TourBus(int numOfSeats);
        bool validTour() const;
        TourBus& board();
        void startTheTour() const;
        ~TourBus();
    };
}

#endif