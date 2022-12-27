/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 10 November 2022
*/

#ifndef __SDDS_MENU_H__
#define __SDDS_MENU_H__

#include <iostream>
#include <string.h>
#include <iomanip>

namespace sdds
{
    class Menu;

    class MenuItem
    {
        char m_content[51];
        friend class Menu;
        MenuItem(const char *content = nullptr);
        std::ostream &display(std::ostream &os = std::cout) const;
        MenuItem(const MenuItem &src) = delete;
        MenuItem &operator=(const MenuItem &src) = delete;
    };

    const int MAX_NO_OF_ITEMS = 10;

    class Menu
    {
        char m_title[51];
        MenuItem m_menuItems[MAX_NO_OF_ITEMS];
        int m_noOfItems;
        int m_indentation;

    public:
        Menu(const char *title = nullptr, int indentation = 0);
        Menu(const Menu &src) = delete;
        Menu &operator=(const Menu &src) = delete;
        operator bool() const;
        bool isEmpty() const;
        std::ostream &display(std::ostream &os = std::cout) const;
        Menu &operator=(const char *title);
        void add(const char *content);
        Menu &operator<<(const char *content);
        void clear();
        operator int() const;
        int run() const;
    };
}

#endif