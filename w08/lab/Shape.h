/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 18 November 2022
*/

#pragma once
#ifndef _SDDS_SHAPE_H_
#define _SDDS_SHAPE_H_
#include <iostream> 

namespace sdds {

	class Shape {
	public:
		virtual ~Shape() {};
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;

	};

	std::ostream& operator<<(std::ostream& os, const Shape& RHS);
	std::istream& operator>>(std::istream& is, Shape& RHS);
}


#endif
