/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 18 November 2022
*/

#ifndef _SDDS_LblShape_H_
#define _SDDS_LblShape_H_
#include <string>
#include <iostream>
#include <cstring>
#include "Shape.h"


namespace sdds {
	class LblShape : public Shape {
	private:
		char* m_label = nullptr;

	protected:
		char* label() const;

	public:
		LblShape();
		LblShape(const char* incomingCstring);
		virtual ~LblShape();
		LblShape(LblShape&) = delete;
		void operator=(const LblShape&) = delete;
		void getSpecs(std::istream& is);

	};


}

#endif
