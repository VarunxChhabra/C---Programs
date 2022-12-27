/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 31 October 2022
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class Numbers
    {
        double* m_numbers{};
        char* m_filename{};
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty() const;
        void setEmpty();
        void deallocate();
        void setFilename(const char* filename);
        Numbers& sort(bool ascending);

    public:
        Numbers();
        Numbers(const char* filename);
        double average() const;
        double max() const;
        double min() const;
        ~Numbers();
        Numbers(const Numbers& N);
        Numbers& operator=(const Numbers& N);
        Numbers operator-() const;
        Numbers operator+() const;
        int numberCount() const;
        bool load();
        void save() const;
        Numbers& operator+=(double value);
        std::ostream& display(std::ostream& ostr) const;
        friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
        friend std::istream& operator>>(std::istream& istr, Numbers& N);
    };
}
#endif // !SDDS_NUMBERS_H_
