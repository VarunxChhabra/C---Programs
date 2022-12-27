/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 22 October 2022
*/

#include "Mark.h"

using namespace std;

namespace sdds
{
    // This is used to store marks upto 100 only in the class's object
    Mark::Mark(int mark)
    {
        if (mark >= 0 && mark <= 100)
        {
            m_mark = mark;
        }
        else
        {
            m_mark = -1;
        }
    }

// This function is used to return gpa by checking the default criteria for the marks 

    Mark::operator double() const
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            if (m_mark < 50)
            {
                return 0.0;
            }
            else if (m_mark < 60)
            {
                return 1.0;
            }
            else if (m_mark < 70)
            {
                return 2.0;
            }
            else if (m_mark < 80)
            {
                return 3.0;
            }
            else
            {
                return 4.0;
            }
        }
        else
        {
            return 0;
        }
    }

    // This Function is used to return the marks stored in the class
    Mark::operator int() const
    {
        if (m_mark != -1)
        {
            return m_mark;
        }
        else
        {
            return 0;
        }
    }

    // This is used to grade according to the marks obtained

    Mark::operator char() const
    {
        char grade = 'X';
        if (m_mark >= 0 && m_mark < 50)
        {
            grade = 'F';
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            grade = 'D';
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            grade = 'C';
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            grade = 'B';
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            grade = 'A';
        }
        return grade;
    }

    Mark::operator bool() const
    {
        return m_mark >= 0 && m_mark <= 100;
    }

    bool Mark::operator==(const Mark& RO) const
    {
        return m_mark == RO.m_mark;
    }

    bool Mark::operator!=(const Mark& RO) const
    {
        return m_mark != RO.m_mark;
    }

    bool Mark::operator<(const Mark& RO) const
    {
        return m_mark < RO.m_mark;
    }

    bool Mark::operator>(const Mark& RO) const
    {
        return m_mark > RO.m_mark;
    }

    bool Mark::operator<=(const Mark& RO) const
    {
        return m_mark <= RO.m_mark;
    }

    bool Mark::operator>=(const Mark& RO) const
    {
        return m_mark >= RO.m_mark;
    }

    // pre increment of the marks
    Mark& Mark::operator++()
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark++;
        }
        return *this;
    }

    // pre decreasing the marks funcction
    Mark& Mark::operator--()
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark--;
        }
        return *this;
    }
    // post increament of the marks
    Mark Mark::operator++(int)
    {
        Mark temp = *this;
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark++;
        }
        return temp;
    }

    // post decreasing the marks
    Mark Mark::operator--(int)
    {
        Mark temp = *this;
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark--;
        }
        return temp;
    }

    bool Mark::operator~() const
    {
        return m_mark >= 50 && m_mark <= 100;
    }

    Mark& Mark::operator=(int mark)
    {
        m_mark = mark;

        return *this;
    }
    Mark& Mark::operator+=(int mark)
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark += mark;
            if (m_mark > 100)
            {
                m_mark = 100;
            }
        }
        return *this;
    }

    Mark& Mark::operator-=(int mark)
    {
        if (m_mark >= 0 && m_mark <= 100)
        {
            m_mark -= mark;
            if (m_mark < 0)
            {
                m_mark = 0;
            }
        }
        return *this;
    }

    int operator+=(int& value, const Mark& RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            value += RO.m_mark;
        }
        return value;
    }
 ;
    int operator-=(int& value, const Mark& RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            value -= RO.m_mark;
        }
        return value;
    }
    Mark operator+(const Mark& LO, int value)
    {
        Mark temp = LO;
        if (LO.m_mark >= 0 && LO.m_mark <= 100)
        {
            temp.m_mark += value;
        }
        return temp;
    }

    Mark operator+(const Mark& LO, const Mark& RO)
    {
        Mark temp = LO;
        if (LO.m_mark >= 0 && LO.m_mark <= 100)
        {
            temp.m_mark += RO.m_mark;
        }
        return temp;
    }

    Mark& Mark::operator>>(Mark& RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            RO.m_mark += m_mark;
            m_mark = 0;
            if (RO.m_mark > 100)
            {
                RO.m_mark = 100;
            }
        }
        return *this;
    }

    Mark& Mark::operator<<(Mark& RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            m_mark += RO.m_mark;
            RO.m_mark = 0;
            if (m_mark > 100)
            {
                m_mark = 100;
            }
        }
        return *this;
    }

    int operator+(int value, const Mark RO)
    {
        if (RO.m_mark >= 0 && RO.m_mark <= 100)
        {
            value += RO.m_mark;
        }
        return value;
    }
}
