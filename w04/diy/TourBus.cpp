/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 10 October 2022
*/

#include "TourBus.h"

using namespace std;

namespace sdds
{
    // This function is used to validate the tour type only if number of seats is 4 , 16 or 22
    TourBus::TourBus(int numOfSeats)
    {
        if (numOfSeats == 4 || numOfSeats == 16 || numOfSeats == 22)
        {
            noSeats = numOfSeats;
            ticket = new TourTicket[noSeats];
            noTicket = 0;
        }
        else
        {
            noSeats = 0;
            ticket = nullptr;
            noTicket = 0;
        }
    }

    // This function is used to validate the tour if no of seats are greater than 0
    bool TourBus::validTour() const
    {
        return noSeats > 0;
    }

    // This function is used to board the passengers by taking the input of the passengers
    // name and issue the ticket 
    TourBus& TourBus::board()
    {
        cout << "Boarding " << noSeats << " Passengers:" << endl;
        for (int i = 0; i < noSeats; i++)
        {
            cout << i + 1 << "/" << noSeats << "- Passenger Name: ";
            char name[41];
            cin.getline(name, 41, '\n');
            ticket[i].issue(name);
            noTicket++;
        }
        return *this;
    }

    // This is function only validate if no. of tickets is equal else it will print the message that tour cannot start
    //  to number of seats and prints the final output

    void TourBus::startTheTour() const
    {
        int i;
        if (validTour() && noTicket == noSeats)
        {
            cout << "Starting the tour...." << endl;
            cout << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
            cout << "+----+------------------------------------------+-----+" << endl;
            for (i = 0; i < noSeats; i++)
            {
                cout << "| " << setw(2) << i + 1 << " ";
                ticket[i].display();
                cout << endl;
            }
            cout << "+----+------------------------------------------+-----+" << endl;
        }
        else
        {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }
    }

    // This is used to delete the dynmaic memory and is also a destructor
    TourBus::~TourBus()
    {
        delete[] ticket;
    }
}
