/* Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 16 September 2022*/

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

#include "ShoppingRec.h"
#include "File.h"
#include "Utils.h"

namespace sdds
{


	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif