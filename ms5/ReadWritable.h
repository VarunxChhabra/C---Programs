
/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 09 December 2022
*/

#ifndef __SDDS_READWRITABLE_H__
#define __SDDS_READWRITABLE_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class ReadWritable
    {
        bool m_commaSeparated;

    public:
        ReadWritable();
        ReadWritable(const ReadWritable& src);
        ReadWritable& operator=(const ReadWritable& src);
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool value);
        virtual std::istream& read(std::istream& istr = std::cin) = 0;
        virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
        friend std::istream& operator>>(std::istream& istr, ReadWritable& rw);
        friend std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw);
    };
}

#endif