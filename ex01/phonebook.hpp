#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "header.hpp"

class PhoneBook
{
    int NbContact;
    Contact contacts[8];
public:
    PhoneBook()
    {
        NbContact = 0;
    }
    void AddContact(Contact ct)
    {
        if(NbContact < 8)
        {
            ct.Index = NbContact+1;
            contacts[NbContact] = ct;
            NbContact ++;
        }
        else
        {
            for (int i = 1; i < 8 ; i++)
            {
                contacts[i].Index = i;
                contacts[i-1] = contacts[i];
            }
            ct.Index = NbContact;
            contacts[7] = ct;
        }
    }
    void ShowContacts()
    {
        for (int i = 0; i < NbContact; i++)
            contacts[i].ShowContact();
        cout << "--------------------------------------------\n";
    }
    void SingleContact(int idx)
    {
        bool bo = false;
        for (int i = 0; i < 8; i++)
        {
            if(contacts[i].Index == idx)
            {
                contacts[i].ShowContact();
                cout << "--------------------------------------------"<< endl;
                bo = true;
                break ;
            }
        }
        if(!bo)
            cout << "There is no contact in the INDEX ["<< idx << "].\n";
    }
};




#endif