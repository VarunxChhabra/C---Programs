/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 16 October 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "Apartment.h" 

using namespace std;
namespace sdds
{
	Apartment::Apartment(int number, double balance)
	{

		if (number >= 1000 && number <= 9999
			&& balance >= 0)
		{
			m_Num = number;
			m_balance = balance;
		}
	}
	std::ostream& Apartment::display() const
	{
		if (*this)
		{
			cout.width(4);
			cout << m_Num;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else
		{
			cout << "Invld|  Apartment   ";
		}
		return cout;
	}// 

	Apartment::operator bool() const {
		if (this->m_Num >= 1000 && this->m_Num <= 9999 && this->m_balance >= 0) {
			return true;
		}

		return false;
	}

	Apartment::operator int() const {
		return this->m_Num;
	}

	Apartment::operator double() const {
		return this->m_balance;
	}

	bool Apartment::operator~()const
	{
		if (this->m_balance < 0.00001) {
			return true;
		}
		return false;
	}

	Apartment& Apartment::operator=(const int aptno) {
		if (aptno >= 1000 && aptno <= 9999)
		{
			this->m_Num = aptno;
		}
		else {
			this->m_Num = -1;
			this->m_balance = 0.0;
		}
		return *this;
	}

	Apartment& Apartment::operator=(Apartment& rightSide) {

		double temp_balance = this->m_balance;
		int temp_number = this->m_Num;

		this->m_balance = rightSide.m_balance;
		this->m_Num = rightSide.m_Num;

		rightSide.m_balance = temp_balance;
		rightSide.m_Num = temp_number;

		return *this;
	}

	Apartment& Apartment::operator+=(const double value) {
		if (*this && value >= 0) {
			this->m_balance += value;
		}
		return *this;
	}

	Apartment& Apartment::operator-=(const double value)
	{
		if (*this && this->m_balance >= value && value >= 0) {

			this->m_balance -= value;
		}
		return *this;
	}

	Apartment& Apartment::operator<<(Apartment& rightSide)
	{
		if (this->m_Num != rightSide.m_Num && rightSide.operator bool() && *this) {
			this->m_balance += rightSide.m_balance;
			rightSide.m_balance = 0;
		}
		return *this;
	}

	Apartment& Apartment::operator>>(Apartment& rightSide)
	{
		if (this->m_Num != rightSide.m_Num && rightSide.operator bool() && *this) {
			rightSide.m_balance += this->m_balance;
			this->m_balance = 0;
		}
		return *this;
	}

	double operator+(const Apartment& leftSide, const Apartment& rightSide)
	{
		if (leftSide.operator bool() && rightSide.operator bool()) {
			double value = 0;
			value = leftSide.m_balance + rightSide.m_balance;
			return value;
		}
		return 0;
	}


	double operator+=(double& value, const Apartment& rightSide)
	{
		value = value + rightSide.m_balance;
		return value;
	}

}