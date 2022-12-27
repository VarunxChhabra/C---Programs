/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 02 December 2022
*/

#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
    class ReadWrite {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual ~ReadWrite() {
        }
    };
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
    std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_
