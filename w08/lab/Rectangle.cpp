/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 18 November 2022
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
#include "Utils.h"

namespace sdds {

	Rectangle::Rectangle()
	{
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* Rec_label, int width, int height) :LblShape(Rec_label)
	{
		if (height < 3 || width < (ut.strlen(Rec_label) + 2)) {
			m_height = 0;
			m_width = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		int t_width, t_height;
		is >> t_width;
		is.ignore(1000, ',');
		is >> t_height;
		is.ignore(1000, '\n');
		m_width = t_width;
		m_height = t_height;
	}

	void Rectangle::draw(std::ostream& os) const
	{
		if (m_height != 0 || m_width != 0) {
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << std::endl;
		

			os << "|";
			os.width(m_width - 2);
			os.setf(std::ios::left);
			os << label();
			os.unsetf(std::ios::left);
			os << "|" << std::endl;
			

			for (int j = 0; j < m_height - 3; j++) {
				os << "|";
				for (int i = 0; i < m_width - 2; i++) {
					os << " ";
				}
				os << "|" << std::endl;
			}
	
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+";
		}
	}


}
