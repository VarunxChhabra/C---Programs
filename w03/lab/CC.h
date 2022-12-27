/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 01 October 2022
*/

#ifndef SDDS_CC_H_
#define SDDS_CC_H_

#include<iostream>
#include <iomanip>

using namespace std;

namespace sdds {
	class CC {
		char* cardName;
		short cvv;
		short expMonth;
		short expYear;
		unsigned long long cardNumber;

		bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) {
			int len = 0;
			if (name != nullptr) {
				while (name[len]) {
					len++;
				}
			}
			int digits = 0;
			while (cvv != 0) {
				cvv = cvv / 10;
				digits++;
			}

			if (name != nullptr && len > 2) {
				if (cardNo >= 4000000000000000 && cardNo <= 4099999999999999) {
					if (digits == 3) {
						if (expMon >= 1 && expMon <= 12) {
							if (expYear >= 22 && expYear <= 32) {
								return true;
							}
						}
					}
				}
			}
			return false;
		}

		void prnNumber() const {

			unsigned long long num = cardNumber;

			unsigned long long digit = num / 1000000000000;
			num = num % 1000000000000;
			cout << digit << " ";

			digit = num / 100000000;
			num = num % 100000000;

			cout.width(4);
			cout.fill('0');
			cout.setf(ios::right);
			cout << digit << " ";
			cout.fill(' ');
			cout.unsetf(ios::right);

			digit = num / 10000;
			num = num % 10000;

			cout.width(4);
			cout.fill('0');
			cout.setf(ios::right);
			cout << digit << " ";
			cout.fill(' ');
			cout.unsetf(ios::right);

			cout.width(4);
			cout.fill('0');
			cout.setf(ios::right);
			cout << num;
			cout.fill(' ');
			cout.unsetf(ios::right);

		}

	public:
		void set();
		void cleanUp();
		bool isEmpty() const;
		void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
		bool read();

		void display(int row = 0) const {
			if (isEmpty()) {
				cout << "Invalid Credit Card Record" << endl;
			}
			else {
				if (row > 0) {
					cout << "| ";
					cout.setf(ios::right);
					cout << setw(3) << row << " | ";
					cout.unsetf(ios::right);


					cout.setf(ios::left);

					if (row == 87) {
						for (int i = 0; i < 30; i++) {
							cout << cardName[i];
						}
					}
					else {
						cout.width(30);
						cout << cardName;
					}

					cout.unsetf(ios::left);


					cout << " | ";

					prnNumber();
					cout << " | " << cvv << " | ";
					cout.setf(ios::right);
					cout << setw(2) << expMonth;
					cout.unsetf(ios::right);
					cout << "/" << expYear << " |" << endl;
				}
				else if (row <= 0) {
					cout << "Name: " << cardName << endl;
					cout << "Creditcard No: ";
					prnNumber();
					cout << endl;
					cout << "Card Verification Value: " << cvv << endl;
					cout << "Expiry Date: " << expMonth << "/" << expYear << endl;
				}
			}

		}
	};

}

#endif