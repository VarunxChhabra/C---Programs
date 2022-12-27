/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 18 November 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include "LblShape.h"
#include "Utils.h"

namespace sdds {

    char* sdds::LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape()
    {
    }

    LblShape::LblShape(const char* inpStr)
    {
        m_label = new char[ut.strlen(inpStr) + 1];
        ut.strcpy(m_label, inpStr);
    }

    LblShape::~LblShape()
    {
        delete[]m_label;
    }

    void LblShape::getSpecs(std::istream& is) 
    {
        std::string str;
        std::getline(is, str, ',');
 
        delete[] this->m_label;
        this->m_label = new char[ut.strlen(str.c_str()) + 1];

        ut.strcpy(m_label, str.c_str());

    }




}
