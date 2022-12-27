/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 22 October 2022
*/

#ifndef __SDDS_MARK_H__
#define __SDDS_MARK_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class Mark
    {
        int m_mark;

    public:
        Mark(int mark = 0);
        explicit operator double() const;
        explicit operator int() const;
        explicit operator char() const;
        explicit operator bool() const;
        bool operator==(const Mark& RO) const;
        bool operator!=(const Mark& RO) const;
        bool operator<(const Mark& RO) const;
        bool operator>(const Mark& RO) const;
        bool operator<=(const Mark& RO) const;
        bool operator>=(const Mark& RO) const;
        Mark& operator++();
        Mark& operator--();
        Mark operator++(int);
        Mark operator--(int);
        bool operator~() const;
        Mark& operator=(int value);
        Mark& operator+=(int value);
        Mark& operator-=(int value);
        friend int operator+=(int& value, const Mark& RO);
        friend int operator-=(int& value, const Mark& RO);
        friend Mark operator+(const Mark& LO, int value);
        friend Mark operator+(const Mark& LO, const Mark& RO);
        friend int operator+(int value, const Mark RO);
        Mark& operator<<(Mark& RO);
        Mark& operator>>(Mark& RO);
    };
}

#endif