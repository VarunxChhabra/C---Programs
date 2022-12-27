/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 26 September 2022
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulationsComplete.csv"
#include "File.h"

namespace sdds
{
    struct Report
    {
        char* postal;
        int population;
    };

    void sort();
    bool load(Report& st);
    bool load(const char filename[]);
    void testdisplay(Report& st);
    void display();
    void deallocateMemory();
}

#endif // SDDS_POPULATION_H_