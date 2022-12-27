/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 02 December 2022
*/

#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        return c.display(os);
    }

    istream& operator >> (istream& is, ReadWrite& c) {
        return c.read(is);
    }
}