/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 02 November 2022
*/
#include "Basket.h"

using namespace std;

namespace sdds
{
    // CONSTRUCTOR FOR THE BASKET

    Basket::Basket()
    {
        m_fruits = nullptr;
        m_size = 0;
        m_price = 0.0;
    }

    // CHECKS THE PARAMETER FRUIT IF NOT NULL IT STORES IT DYNAMICALLY

    Basket::Basket(Fruit* fruits, int size, double price)
    {
        if (fruits != nullptr && size > 0 && price > 0)
        {
            m_fruits = new Fruit[size];
            for (int i = 0; i < size; i++)
            {
                m_fruits[i] = fruits[i];
            }
            m_size = size;
            m_price = price;
        }
        else
        {
            m_fruits = nullptr;
            m_size = 0;
            m_price = 0.0;
        }
    }

    // HERE THE USE OF COPY CONSTRUCTOR THAT IS USED TO COPY THE m_fruits BY 
    // DEEP COPY AND FOR OTHER ATTRIBUTES SHALLOW COPY BECAUSE THEY ARE NOT DYNAMICALLY STORED

    Basket::Basket(const Basket& src)
    {
        m_fruits = new Fruit[src.m_size];
        for (int i = 0; i < src.m_size; i++)
        {
            m_fruits[i] = src.m_fruits[i];
        }
        m_size = src.m_size;
        m_price = src.m_price;
    }

    // THIS FUNCTION IS USED AS COPY CONSTRUCTOR OPERATOR

    Basket& Basket::operator=(const Basket& src)
    {
        if (this != &src)
        {
            if (m_size > 0)
                delete[] m_fruits;
            if (src.m_size > 0)
                m_fruits = new Fruit[src.m_size];
            else
                m_fruits = nullptr;
            for (int i = 0; i < src.m_size; i++)
            {
                m_fruits[i] = src.m_fruits[i];
            }
            m_size = src.m_size;
            m_price = src.m_price;
        }
        return *this;
    }

    // THIS IS USED TO DELETE THE DYNAMIC MEMORY FOR THR m_fruits

    Basket::~Basket()
    {
        delete[] m_fruits;
    }

    //  THIS IS USED TO UPDATE THE PRICE

    void Basket::setPrice(double price)
    {
        m_price = price;
    }

    // THIS IS USED TO CHECK IS THERE ANY FRUIT IN BASKET
    // AS IF THERE IS ANY FRUIT THERE WILL BE THE SIZE OF THE BASKET

    Basket::operator bool() const
    {
        return m_size > 0;
    }

    // THIS IS USED TO OVERLOAD THE FRUIT AND STORING IT DYNMAICALLY 

    Basket& Basket::operator+=(Fruit fruit)
    {
        Fruit* temp = new Fruit[m_size + 1];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_fruits[i];
        }
        temp[m_size] = fruit;
        delete[] m_fruits;
        m_fruits = temp;
        m_size++;
        return *this;
    }
    
    //  THIS IS USED FOR OVERLOADING THE INSERTATION AND DISPLAYING THE OUTPUT

    std::ostream& operator<<(std::ostream& os, const Basket& basket)
    {
        if (basket.m_size == 0)
        {
            os << "The basket is empty!" << endl;
        }
        else
        {
            os << "Basket Content:" << endl;
            for (int i = 0; i < basket.m_size; i++)
            {
                os << setw(10) << right << basket.m_fruits[i].m_name << left << ": " << setprecision(2) << fixed << basket.m_fruits[i].m_qty << "kg" << endl;
            }
            os << "Price: " << setprecision(2) << fixed << basket.m_price << endl;
        }
        return os;
    }
}