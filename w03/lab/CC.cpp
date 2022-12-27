/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 01 October 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CC.h"
#include<cstring>
#include<string>
#include <stdio.h>
#include <iostream>
#include "string"

using namespace std;

namespace sdds {

	void CC::set() {
		cardName = nullptr;
		cardNumber = 0;
		cvv = 0;
		expMonth = 0;
		expYear = 0;
	}

	void CC::cleanUp() {
		cardName = nullptr;
		set();
	}

	bool CC::isEmpty() const {
		if (cardName == nullptr) {
			return true;
		}
		return false;
	}

	void CC::set(const char* cc_name, unsigned long long cc_no, short Cvv, short ExpMon, short ExpYear) {

		cleanUp();

		if (validate(cc_name, cc_no, Cvv, ExpMon, ExpYear)) {
			cardName = const_cast<char*>(cc_name);
			cardNumber = cc_no;
			cvv = Cvv;
			expMonth = ExpMon;
			expYear = ExpYear;
		}
	}


	bool CC::read() {
		char TempName[71]{};
		unsigned long long TempNum{};
		short cvv{};
		short TempMonth{};
		short TempYear{};

		cleanUp();
		cout << "Card holder name: ";
		cin >> TempName;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			return false;
		}
		else {
			cout << "Credit card number: ";
			cin >> TempNum;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				return false;
			}
			else {
				cout << "Card Verification Value (CVV): ";
				cin >> cvv;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					return false;
				}
				else {
					cout << "Expiry month and year (MM/YY): ";
					cin >> TempMonth; cin.ignore(); cin >> TempYear;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');
						return false;
					}
					else {
						cin.ignore(10000, '\n');
						set(TempName, TempNum, cvv, TempMonth, TempYear);
						if (isEmpty()) return false;
						else return true;
					}


				}

			}
		}
	}


}