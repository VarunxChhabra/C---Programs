/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 03 October 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include "NameTag.h"

using namespace std;

namespace sdds
{
    NameTag::NameTag()
    {
        name[0] = 0;
    }

    NameTag::NameTag(const char* name)
    {
        strcpy(this->name, name);
    }

    void NameTag::set(const char* name)
    {
        strcpy(this->name, name);
    }

    char* NameTag::getName() const
    {
        return (char*)name;
    }
}
