/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 02 November 2022
*/

#ifndef __SDDS_BASKET_H__
#define __SDDS_BASKET_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    struct Fruit
    {
        char m_name[30 + 1]; 
        double m_qty;        
    };

    class Basket
    {
        Fruit* m_fruits;
        int m_size;
        double m_price;

    public:
        Basket();
        Basket(Fruit* fruits, int size, double price);
        Basket(const Basket& src);
        Basket& operator=(const Basket& src);
        ~Basket();
        void setPrice(double price);
        operator bool() const;
        Basket& operator+=(Fruit fruit);
        friend std::ostream& operator<<(std::ostream& os, const Basket& basket);
    };

}

#endif
