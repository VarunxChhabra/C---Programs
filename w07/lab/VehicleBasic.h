/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 11 November 2022
*/

#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	const int plate_size = 10;
	const int size_address = 65;
	class VehicleBasic {
	protected:
		char licensePlate[plate_size];
		char address[size_address];
		int year;

	public:
		VehicleBasic(const char* licPlate, int vYear);
		void NewAddress(const char* addr);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);

		friend std::istream& operator >> (std::istream& in, VehicleBasic& vBasic);
		friend std::ostream& operator << (std::ostream& os, VehicleBasic vBasic);

	};
}

#endif