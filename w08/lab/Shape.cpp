/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 18 November 2022
*/

#include <iostream>
#include "Shape.h"
#include "Utils.h"

namespace sdds {

	std::ostream& operator<<(std::ostream& os, const Shape& RHS)
	{
		RHS.draw(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Shape& RHS)
	{
		RHS.getSpecs(is);
		return is;

	}

}