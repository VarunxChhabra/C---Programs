
/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 25 November 2022
*/

#ifndef SDDS_HtmlText_H
#define SDDS_HtmlText_H
#include "Text.h"

namespace sdds
{
	class HtmlText : public Text {
	private:
		char* m_title{};
	public:
		HtmlText();
		HtmlText(const char* text);
		~HtmlText();
		HtmlText(const HtmlText* Html_Text);
		HtmlText& operator=(const HtmlText& Html_Text);
		std::ostream& write(std::ostream& os) const override;
		friend std::ostream& operator<<(std::ostream& is, const HtmlText& Html_Text);
		friend std::istream& operator>>(std::istream& is, HtmlText& Html_Text);
	};
}

#endif