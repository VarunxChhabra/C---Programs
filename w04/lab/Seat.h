/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 07 October 2022
*/

#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream> 
namespace sdds {
	class Seat {
		bool validate(int row, char letter)const; 
		Seat& alAndCp(const char* str);
		char* passName;
		int rowNum;
		char letterVal;
		int sizeCount(const char* msg);

	public:

		Seat();
		Seat(const char* passengerName);
		Seat(const char* passengerName, int row, char letter);
		Seat& reset();
		bool isEmpty() const;
		bool assigned() const;
		~Seat();
		Seat& set(int row, char letter);
		int row() const;
		char letter()const;
		const char* passenger()const;
		std::ostream& display(std::ostream& countRef = std::cout) const;
		std::istream& read(std::istream& cinRef = std::cin);
	};
}
#endif