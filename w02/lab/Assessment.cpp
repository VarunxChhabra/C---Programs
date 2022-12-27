
/* Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 23 September 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
using namespace std;

namespace sdds
{
	bool read(int& value, FILE* fptr)
	{
		int x = fscanf(fptr, "%d", &value);
		return x == 1;

	}
	// This is used to read the integer from the file one by one 
	// and returns true if it is successful

	bool read(double& value, FILE* fptr)
	{
		int x = fscanf(fptr, "%lf", &value);
		return x == 1;

	}
	// This is used to read the double from the file one by one 
	// and returns true if it is successful

	bool read(char* cstr, FILE* fptr)
	{
		int x = fscanf(fptr, ",%60[^\n]\n", cstr);
		return x == 1;
	}
	
	// This is used to read the 60 character long string by skipping the commas 
	// from the file one by one and returns true if it is successful
	
	bool read(Assessment& asmnt, FILE* fptr)
	{
		bool result = false;
		if (fptr != NULL)
		{
			double d{};
			char str[61]{};
			if (read(d, fptr) && read(str, fptr))
			{
				asmnt.m_mark = new double;
				asmnt.m_title = new char[strlen(str) + 1];
				
				*asmnt.m_mark = d;
				strcpy(asmnt.m_title, str, strlen(str));
				result = true;
			}
		}
		return result;
	}

	// This is used to read the double first and then the 60 characters and store it in the 
	// dynamic memory to the exact size of the read cstring from the files

	void freeMem(Assessment*& aptr, int size)
	{
		if (aptr != NULL)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] aptr[i].m_title;
				aptr[i].m_title = nullptr;
				delete aptr[i].m_mark;
				aptr[i].m_mark = nullptr;
			}
			delete[] aptr;
			aptr = nullptr;
		}

	}

	// This function is used to delete the dynamic memories array for the double and cstrings 

	int read(Assessment*& aptr, FILE* fptr)
	{
		int x = 0;
		bool result = read(x, fptr);
		if (result)
		{
			aptr = new Assessment[x];
			int i = 0;
			for (i = 0; i < x; i++)
			{
				aptr[i].m_mark = nullptr;
				aptr[i].m_title = nullptr;
			}
			for (i = 0; i < x; i++)
			{
				bool result_2 = read(aptr[i], fptr);
				if (!result_2)
				{
					freeMem(aptr, x);
					return 0;
				}
			}
			return x;
		}
		else
		{
			return 0;
		}
	}
}
// This function is used to read the assement records which are newly allocated in 
// the dynamic memory here in the code x refers to number of records only for this function