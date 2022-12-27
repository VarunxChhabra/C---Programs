/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 24 November 2022
*/

#include "ReadWritable.h"

using namespace std;

namespace sdds
{
    ReadWritable::ReadWritable()
    {
        m_commaSeparated = false;
    }

    ReadWritable::~ReadWritable()
    {
    }

    bool ReadWritable::isCsv() const
    {
        return m_commaSeparated;
    }

    void ReadWritable::setCsv(bool value)
    {
        m_commaSeparated = value;
    }

    std::istream& operator>>(std::istream& istr, ReadWritable& rw)
    {
        return rw.read(istr);
    }

    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw)
    {
        return rw.write(ostr);
    }
}
