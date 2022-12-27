/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 03 October 2022
*/
#ifndef __SDDS_TAGLIST_H__
#define __SDDS_TAGLIST_H__

#include <iostream>
#include <string.h>
#include <iomanip>
#include "NameTag.h"
namespace sdds
{
    class TagList
    {
        // Creating a class so that it can hold the names dynamically 
        NameTag* tags;
        int no_of_tags;
        int current;
        int longest_name;

    public:
        void set();
        void set(int num);
        void add(const NameTag& nt);
        void print();
        void cleanup();
    };
}

#endif