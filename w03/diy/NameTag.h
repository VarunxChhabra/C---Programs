/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 03 October 2022
*/

#ifndef __SDDS_NAMETAG_H__
#define __SDDS_NAMETAG_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class NameTag
    {
        char name[51];

    public:
        NameTag();
        NameTag(const char* name);
        void set(const char* name);
        char* getName() const;
    };
}

#endif
