/* Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 16 September 2022*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "ShoppingRec.h"

namespace sdds
{


	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif