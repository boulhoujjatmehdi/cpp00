
#include "header.hpp"

Contact add()
{
	Contact cont;

		cont.Index = 0;
		cout << "FirstName : ";
		getline(cin, cont.FirstName);
		if(cont.FirstName.empty())
			cont.Index = -1;
		cout << "LastName : ";
		getline(cin, cont.LastName);
		if(cont.LastName.empty())
			cont.Index = -1;
		cout << "Nickname : ";
		getline(cin, cont.Nickname);
		if(cont.Nickname.empty())
			cont.Index = -1;
		cout << "PoneNumber : ";
		getline(cin, cont.PoneNumber);
		if(cont.PoneNumber.empty())
			cont.Index = -1;
		cout << "DarkestSecret : ";
		getline(cin, cont.DarkestSecret);
		if(cont.DarkestSecret.empty())
			cont.Index = -1;
	return cont;
}

bool containsNonNumeric(string str)
{

	for (int i = 0; str[i];i++)
	{
		if(i == 0 && (str[0] == '-' || str[i] == '+'))
			i++;
		if(!isdigit(str[i]))
			return true;
	}
	return false;
}

void search(PhoneBook phonebook)
{
	phonebook.ShowContacts();
	cout << "INDEX :";
	string str;
	getline(cin, str);
	if(str.empty() || containsNonNumeric(str))
		return ;
	int nb = stoi(str);
	phonebook.SingleContact(nb);
}

int main()
{ 
	PhoneBook phonebook;
	Contact ct;
	ct.SetContact("mehdi123456789", "boulhoujjat", "lberzekh", "0631548798465456", "serkil");
	phonebook.AddContact(ct);
		cout << "PROGRAM STARTED\n\n";
	string str;
	while(1)
	{
		cout << "Available Options(ADD - SEARCH - EXIT)\n";
		getline(cin, str);
		if(!strcmp("EXIT", str.c_str()))
			exit(0);
		else if(!strcmp("ADD", str.c_str()))
		{
			ct = add();
			if(ct.Index != -1)
				phonebook.AddContact(ct);
			else
				cout << "!!!Veryfy your inputs you have sent one empty!!!" << ct.Index << endl	;
		}
		else if(!strcmp("SEARCH", str.c_str()))
		{
			search(phonebook);
		}
	}
	phonebook.ShowContacts();

}
