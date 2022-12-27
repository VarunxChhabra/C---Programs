/*
Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 26 September 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include <cstring>
using namespace std;

namespace sdds
{
    Report* report;
    int noOfPopulations;

    // Ths is function is use to sort the reports 
    void sort()
    {
        int i, j;
        Report temp;
        for (i = noOfPopulations - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (report[j].population > report[j + 1].population)
                {
                    temp = report[j];
                    report[j] = report[j + 1];
                    report[j + 1] = temp;
                }
            }
        }
    }

    // This function is use to load  the reports and use to 
    // store data in the dynamic memory for the postal code
    bool load(Report& st)
    {
        bool result = false;
        char postalcode[128];
        if (read(postalcode) && (read(st.population)))
        {
            st.postal = new char[strlen(postalcode) + 1];
            strcpy(st.postal, postalcode);
            result = true;
            return result;
        }
        else
        {
            return result;
        }
    }

    // This function is use to load the file and use to
    // count the no. of population for each of the postal code

    bool load(const char filename[])
    {
        bool result = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            result = true;
            noOfPopulations = noOfRecords();
            report = new Report[noOfPopulations];
            for (i = 0; result && i < noOfPopulations; i++)
            {
                result = load(report[i]);
            }
            if (!result)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                result = true;
            }
            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return result;
    }

    // This function is used to display the reports by 
    // showing postal code first and then ": " at last number of population
    void testdisplay(Report& st)
    {
        cout << st.postal << ":  " << st.population << endl;
    }

    // This function is used to count the total number of the population mention in the report
    int totalPopulation()
    {
        int total = 0;
        for (int i = 0; i < noOfPopulations; i++)
            total += report[i].population;
        return total;
    }

    // This function is used to display the full table of the required output
    void display()
    {
        sort();
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        int i, j;
        for (i = 0, j = 1; i < noOfPopulations; i++) {
            cout << j++ << "- ";
            testdisplay(report[i]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation() << endl;
    }

    // This function is used to delete the dynamic memory
    void deallocateMemory()
    {
        for (int i = 0; i < noOfPopulations; i++)
        {
            delete[] report[i].postal;
        }
        delete[] report;
        report = nullptr;
    }

}