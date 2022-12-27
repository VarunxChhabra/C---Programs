/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 07 October 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h" 
#include <iostream> 
#include <cstring> 
using namespace std;
namespace sdds {

	// Function to validate the rows and the setting letters
	bool Seat::validate(int row, char letter)const 
	{
		if (row >= 1 && row <= 4)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (row >= 7 && row <= 15)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F' || letter == 'C' || letter == 'D')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (row >= 20 && row <= 38)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F' || letter == 'C' || letter == 'D')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	// Using current obejct to retrun the stored string
	Seat& Seat::alAndCp(const char* str)
	{
		return *this;
	}

	int Seat::sizeCount(const char* msg)
	{
		int i;
		for (i = 0; msg[i] != '\0'; i++)
		{

		}
		return i;
	}
	Seat& Seat::reset()
	{
		delete[] passName;
		passName = nullptr;
		rowNum = 0;;
		letterVal = 0;
		return *this;
	}

	// to check the the passenger name is in the safe empty state
	bool Seat::isEmpty() const
	{
		if (passName == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// To check the seats assigned are valid 
	bool Seat::assigned() const
	{
		if (rowNum != 0 && letterVal != 0)
		{
			if (validate(rowNum, letterVal))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	// Reseting the object into a safe empty state
	Seat::Seat()
	{
		passName = nullptr;
		rowNum = 0;;
		letterVal = 0;
	}

	// Creating argument constructor for passengerName
	Seat::Seat(const char* passengerName)
	{
		if (passengerName != nullptr && passengerName[0] != '\0')
		{
			passName = new char[sizeCount(passengerName) + 1];
			strcpy(passName, passengerName);
			rowNum = 0;
			letterVal = 0;
		}
		else
		{
			passName = nullptr;
			rowNum = 0;
			letterVal = 0;
		}


	}
	// constructor for all three objects
	Seat::Seat(const char* passengerName, int row, char letter)
	{
		if (passengerName != nullptr && passengerName[0] != '\0')
		{
			passName = new char[sizeCount(passengerName) + 1];
			strcpy(passName, passengerName);
			rowNum = row;
			letterVal = letter;
		}
		else
		{
			passName = nullptr;
			rowNum = 0;
			letterVal = 0;
		}
	}
	// Using destructor
	Seat::~Seat()
	{
		delete[] passName;
		passName = nullptr;

	}

	//This is used to validate the row and letter
	Seat& Seat::set(int row, char letter)
	{
		if (validate(row, letter))
		{
			rowNum = row;
			letterVal = letter;
		}
		else
		{
			rowNum = row;
			letterVal = letter;
		}
		return *this;
	}

	// return the row
	int Seat::row() const
	{
		return rowNum;
	}

	// return the letter
	char Seat::letter()const
	{
		return letterVal;
	}

	// return the passangers name
	const char* Seat::passenger()const
	{
		return passName;
	}

	// this function is used to print the values
	ostream& Seat::display(ostream& countRef) const
	{
		if (passName != nullptr) 
		{

			int i;

			for (i = 0; i < 40 && passName[i] != '\0'; i++)
			{
				countRef << passName[i];
			}
			while (i < 40)
			{
				countRef << ".";
				i += 1;
			}
			countRef << " ";
			if (validate(rowNum, letterVal))
			{
				countRef << rowNum << letterVal;
			}
			else
			{
				countRef << "___";
			}
		}
		else
		{
			countRef << "Invalid Seat!";
		}
		return countRef;
	}

	// this function is used to extract the values
	istream& Seat::read(istream& cinRef)
	{
		delete[] passName;
		passName = new char[71];
		cinRef.getline(passName, 71, ',');
		cinRef >> rowNum;
		cinRef >> letterVal;
		cinRef.ignore();
		return cinRef;
	}
}