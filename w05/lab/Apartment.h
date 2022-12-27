/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 16 October 2022
*/
#ifndef SDDS_APARTMENT_H_ 
#define SDDS_APARTMENT_H_ 
#include <iostream> 

namespace sdds
{
	class Apartment
	{
		int m_Num = -1;
		double m_balance = 0.0;

	public: // public
		Apartment(int num, double balance);
		std::ostream& display()const;

		operator bool() const;
		operator int() const;
		operator double() const;

		bool operator~() const;

		Apartment& operator=(const int aptno);
		Apartment& operator=(Apartment& rightSide);

		Apartment& operator+=(const double value);
		Apartment& operator-=(const double value);

		Apartment& operator<<(Apartment& rightSide);
		Apartment& operator>>(Apartment& rightSide);

		friend double operator+(const Apartment& leftSide, const Apartment& rightSide);
		friend double operator+=(double& value, const Apartment& rightSide);

	};

}

#endif // SDDS_APARTMENT_H_