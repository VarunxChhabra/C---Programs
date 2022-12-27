/* Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 16 September 2022*/

#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H
#include "Utils.h"

namespace sdds
{
	const int MAX_TITLE_LENGTH = 50;

	struct ShoppingRec
	{
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif
