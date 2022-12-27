/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 11 November 2022 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "VehicleBasic.h"
#include "Dumper.h"
using namespace std;

namespace sdds
{
	VehicleBasic::VehicleBasic(const char* licPlate, int vYear) {
		strcpy(licensePlate, licPlate);
		year = vYear;
		strcpy(address, "Factory");
	}
	void VehicleBasic::NewAddress(const char* addr) {
		if (strcmp(address, addr) != 0) {
			cout << "|" << setw(8) << right << licensePlate << "| |" << setw(20) << right << address << " ---> " << setw(20) << left << addr << "|" << endl;
		}
		strcpy(address, addr);
	}

	std::ostream& VehicleBasic::write(std::ostream& os) {
		os << "| " << year << " | " << licensePlate << " | " << address;
		return os;
	}

	std::istream& VehicleBasic::read(std::istream& in) {
		cout << "Built year: ";
		in >> year;

		cout << "License plate: ";
		in >> licensePlate;

		cout << "Current location: ";
		in >> address;

		return in;
	}

	std::istream& operator >> (std::istream& in, VehicleBasic& vBasic) {
		return vBasic.read(in);
	}
	std::ostream& operator << (std::ostream& os, VehicleBasic vBasic) {
		return vBasic.write(os);
	}
	Dumper::Dumper(const char* licPlate, int dYear, int dCapacity, const char* addr) : VehicleBasic(licPlate, dYear) {
		capacity = dCapacity;
		NewAddress(addr);
		currentCargoLoad = 0;
	}

	bool Dumper::loaddCargo(double cargo) {
		double remainingCapacity = capacity - currentCargoLoad;
		if (cargo <= remainingCapacity) {
			currentCargoLoad += cargo;
			return true;
		}
		return false;
	}
	bool Dumper::unloadCargo() {
		if (currentCargoLoad != 0) {
			currentCargoLoad = 0;
			return true;
		}
		return false;
	}
	std::ostream& Dumper::write(std::ostream& os) {
		os << "| " << year << " | " << licensePlate << " | " << address;
		os << " | " << currentCargoLoad << "/" << capacity;
		return os;
	}
	std::istream& Dumper::read(std::istream& in) {
		cout << "Built year: ";
		in >> year;

		cout << "License plate: ";
		in >> licensePlate;

		cout << "Current location: ";
		in >> address;

		cout << "Capacity: ";
		in >> capacity;

		cout << "Cargo: ";
		in >> currentCargoLoad;

		return in;
	}

	std::istream& operator >> (std::istream& in, Dumper& dumper) {
		return dumper.read(in);
	}
	std::ostream& operator << (std::ostream& os, Dumper dumper) {
		return dumper.write(os);
	}

}