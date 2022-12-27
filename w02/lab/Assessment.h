/* Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 23 September 2022
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_ASSESSMENT_H_
#define SDDS_ASSESSMENT_H_
#include "Utils.h"

namespace sdds {
	struct Assessment {
		double* m_mark;
		char* m_title;
	};

	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessment& asmnt, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);

}

#endif
