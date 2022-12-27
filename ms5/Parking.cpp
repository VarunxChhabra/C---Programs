
/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 09 December 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"

using namespace std;

namespace sdds
{
    Parking::Parking(const char* datafile, int noOfSpots) : m_parkingMenu("Parking Menu, select an action:", 0),
        m_vehicleMenu("Select type of the vehicle:", 1)
    {
        for (int i = 0; i < MAX_PARKING_SPOTS; i++)
        {
            m_parkingSpots[i] = nullptr;
        }
        if (noOfSpots < 10 || noOfSpots > MAX_PARKING_SPOTS)
        {
            m_filename = nullptr;
            m_noOfSpots = 0;
            m_noOfParkedVehicles = 0;
        }
        else
        {
            m_noOfSpots = noOfSpots;
            m_noOfParkedVehicles = 0;
            if (datafile == nullptr || datafile[0] == '\0')
            {
                m_filename = nullptr;
            }
            else
            {
                m_filename = new char[strlen(datafile) + 1];
                strcpy(m_filename, datafile);
            }
            if (!loadDataFile())
            {
                cout << "Error in data file" << endl;
            }
            m_parkingMenu << "Park Vehicle"
                << "Return Vehicle"
                << "List Parked Vehicles"
                << "Find Vehicle"
                << "Close Parking (End of day)"
                << "Exit Program";
            m_vehicleMenu << "Car"
                << "Motorcycle"
                << "Cancel";
        }
    }

    Parking::~Parking()
    {
        saveDataFile();
        delete[] m_filename;
        m_filename = nullptr;
        for (int i = 0; i < m_noOfSpots; i++)
        {
            delete m_parkingSpots[i];
            m_parkingSpots[i] = nullptr;
        }
    }

    bool Parking::isEmpty() const
    {
        return m_filename == nullptr;
    }

    void Parking::parkingStatus() const
    {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout << setw(4) << left << (m_noOfSpots - m_noOfParkedVehicles);
        cout << " *****" << endl;
    }

    void Parking::parkVehicle()
    {


        if (m_noOfParkedVehicles == m_noOfSpots)
        {
            cout << "Parking is full" << endl;
        }
        else
        {
            Vehicle* v = nullptr;
            int selection = m_vehicleMenu.run();
            if (selection == 1)
            {
                v = new Car;
            }
            else if (selection == 2)
            {
                v = new Motorcycle;
            }
            else
            {
                cout << "Parking cancelled" << endl;
                cout << "Press <ENTER> to continue....";
                cin.get();
                return;
            }
            v->setCsv(false);
            cin >> *v;
            for (int i = 0; i < m_noOfSpots; i++)
            {
                if (m_parkingSpots[i] == nullptr)
                {
                    m_parkingSpots[i] = v;
                    m_parkingSpots[i]->setParkingSpot(i + 1);
                    cout << endl
                        << "Parking Ticket" << endl;
                    m_parkingSpots[i]->write(cout);
                    cout << endl;
                    m_noOfParkedVehicles++;
                    break;
                }
            }
        }
        cout << "Press <ENTER> to continue....";
        cin.get();
    }

    void Parking::returnVehicle()
    {
        cout << "Return Vehicle" << endl;
        cout << "Enter License Plate Number: ";
        string licencePlate;
        cin >> licencePlate;
        while (licencePlate.length() > 8 || licencePlate.length() < 1)
        {
            cout << "Invalid Licence Plate, try again: ";
            cin >> licencePlate;
        }

        for (size_t i = 0; i < licencePlate.length(); i++)
        {
            licencePlate[i] = toupper(licencePlate[i]);
        }

        cout << endl;
        int i;
        for (i = 0; i < m_noOfSpots; i++)
        {
            if (m_parkingSpots[i] != nullptr && *m_parkingSpots[i] == licencePlate.c_str())
            {
                m_parkingSpots[i]->setCsv(false);
                cout << "Returning:" << endl
                    << *m_parkingSpots[i] << endl;
                delete m_parkingSpots[i];
                m_parkingSpots[i] = nullptr;
                m_noOfParkedVehicles--;
                cout << "Press <ENTER> to continue....";
                cin.get();
                if (cin.peek() == '\n')
                {
                    cin.get();
                }
                return;
            }
        }
        cout << "License plate " << licencePlate << " Not found" << endl;
        cout << endl;
        cout << "Press <ENTER> to continue....";
        cin.get();
        if (cin.peek() == '\n')
        {
            cin.get();
        }
    }

    void Parking::listParkedVehicles() const
    {
        cout << "*** List of parked vehicles ***" << endl;

        for (int i = 0; i < m_noOfSpots; i++)
        {
            if (m_parkingSpots[i] != nullptr)
            {
                m_parkingSpots[i]->setCsv(false);
                m_parkingSpots[i]->write(cout);
                cout << "-------------------------------";
                cout << endl;
            }
        }
        cout << "Press <ENTER> to continue....";
        cin.get();
    }

    void Parking::findVehicle() const
    {
        cout << "Vehicle Search" << endl;

        string licensePlate;
        cout << "Enter Licence Plate Number: ";
        getline(cin, licensePlate);
        while (licensePlate.length() < 1 || licensePlate.length() > 8)
        {
            cout << "Invalid Licence Plate, try again: ";
            getline(cin, licensePlate);
        }

        for (size_t i = 0; i < licensePlate.length(); i++)
        {
            licensePlate[i] = toupper(licensePlate[i]);
        }

        for (int i = 0; i < m_noOfSpots; i++)
        {
            if (m_parkingSpots[i] != nullptr)
            {
                if (*m_parkingSpots[i] == licensePlate.c_str())
                {
                    cout << endl
                        << "Vehicle found:" << endl;
                    m_parkingSpots[i]->setCsv(false);
                    m_parkingSpots[i]->write(cout);
                    cout << endl
                        << "Press <ENTER> to continue....";
                    cin.get();
                    return;
                }
            }
        }
        cout << endl
            << "Licence plate " << licensePlate << " Not found" << endl
            << endl;
        cout << "Press <ENTER> to continue....";
        cin.get();
    }

    bool Parking::closeParking()
    {

        if (m_noOfParkedVehicles == 0)
        {
            cout << "Closing Parking" << endl;
            return true;
        }
        else
        {
            char response;
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            while (true)
            {
                cin >> response;
                if (response == 'Y' || response == 'y')
                {
                    cout << "Closing Parking" << endl;

                    for (int i = 0; i < m_noOfSpots; i++)
                    {
                        if (m_parkingSpots[i] != nullptr)
                        {
                            cout << endl
                                << "Towing request" << endl;
                            cout << "*********************" << endl;
                            m_parkingSpots[i]->setCsv(false);
                            cout << *m_parkingSpots[i];
                            delete m_parkingSpots[i];
                            m_parkingSpots[i] = nullptr;
                        }
                    }
                    return true;
                }
                else if (response == 'N' || response == 'n')
                {
                    return false;
                }
                else
                {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            }
        }
    }

    bool Parking::exitParkingApp() const
    {

        char response;
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        while (true)
        {
            cin >> response;
            if (response == 'Y' || response == 'y')
            {
                return true;
            }
            else if (response == 'N' || response == 'n')
            {
                return false;
            }
            else
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
    }

    bool Parking::loadDataFile()
    {
        bool ok = false;
        if (m_filename != nullptr)
        {
            ifstream datafile(m_filename);

            if (!datafile.is_open())
            {
                if (m_noOfParkedVehicles == 0 && m_noOfSpots == 0)
                {
                    ok = true;
                }
            }
            else
            {
                char type;
                int i = 0;
                while (i < m_noOfSpots)
                {
                    datafile >> type;
                    datafile.ignore();
                    Vehicle* v = nullptr;
                    if (datafile.fail())
                    {
                        break;
                    }
                    if (type == 'M')
                    {
                        v = new Motorcycle;
                    }
                    else if (type == 'C')
                    {
                        v = new Car;
                    }
                    else
                    {
                        v = nullptr;
                    }
                    if (v != nullptr)
                    {
                        v->setCsv(true);
                        datafile >> *v;
                        if (datafile.fail())
                        {
                            ok = false;
                            delete v;
                            v = nullptr;
                            break;
                        }
                        else
                        {
                            m_parkingSpots[v->getParkingSpot() - 1] = v;
                            ok = true;
                            m_noOfParkedVehicles++;
                        }
                    }
                    i++;
                }
            }
        }
        return ok;
    }

    void Parking::saveDataFile() const
    {
        if (m_filename != nullptr)
        {
            ofstream datafile(m_filename);
            if (datafile.is_open())
            {
                for (int i = 0; i < m_noOfSpots; i++)
                {
                    if (m_parkingSpots[i] != nullptr)
                    {
                        m_parkingSpots[i]->setCsv(true);
                        datafile << *m_parkingSpots[i];
                    }
                }
            }
        }
    }

    int Parking::run()
    {
        int selection = 0;
        if (!isEmpty())
        {
            bool continueApp = true;
            do
            {
                parkingStatus();
                selection = m_parkingMenu.run();
                switch (selection)
                {
                case 1:
                    parkVehicle();
                    break;
                case 2:
                    returnVehicle();
                    break;
                case 3:
                    listParkedVehicles();
                    break;
                case 4:
                    findVehicle();
                    break;
                case 5:
                    if (closeParking())
                    {
                        continueApp = false;
                    }
                    break;
                default:
                    if (exitParkingApp())
                    {
                        continueApp = false;
                        cout << "Exiting program!" << endl;
                    }
                    break;
                }
            } while (continueApp);
            if (cin.peek() == '\n')
            {
                cin.get();
            }
            return 0;
        }
        return 1;
    }

}
