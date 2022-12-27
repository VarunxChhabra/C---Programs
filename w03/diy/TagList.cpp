/*
   Name - Varun Chhabra
   Email - vchhabra1@myseneca.ca
   StudentID - 170279210
   Date of Completion - 03 October 2022
*/

#include "TagList.h"

using namespace std;

namespace sdds
{
    // Use to set the taglist to an empty state
    void TagList::set()
    {
        tags = nullptr;
        no_of_tags = 0;
        longest_name = 0;
        current = 0;
    }

    // Calling clean up function then setting the name of the tags dynamically.
    void TagList::set(int num)
    {
        cleanup();
        tags = new NameTag[num];
        no_of_tags = num;
        current = 0;
    }

    // Adds up to num of nametags to the taglist.
    void TagList::add(const NameTag& nt)
    {
        if (current < no_of_tags)
        {
            tags[current] = nt;
            current++;
            int length = strlen(nt.getName());
            if (length > longest_name)
            {
                longest_name = strlen(nt.getName());
            }
        }
    }

    // Prints all the tags with the frame of the longest name size
    void TagList::print()
    {
        int i;

        for (i = 0; i < no_of_tags; i++)
        {
            for (int j = 0; j < longest_name + 4; j++)
            {
                cout << "*";
            }
            cout << endl;
            cout << "* " << setw(longest_name) << left << tags[i].getName() << " *" << endl;

            for (int j = 0; j < longest_name + 4; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Deallocates the dynamic memory for the taglist names and setting it in the safe empty state
    void TagList::cleanup()
    {
        delete[] tags;
        set();
    }
}
