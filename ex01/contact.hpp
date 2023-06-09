#ifndef CONTACT_HPP
#define CONTACT_HPP

	#include "header.hpp"


	void set_ten(char *tmp, string str)
	{
		if(str.length() <= 10)
			memcpy(tmp , str.c_str(), str.length());
		else
		{
			memcpy(tmp, str.substr(0, 10).c_str(), str.substr(0, 10).length());
			tmp[9] = '.';
		}

	}




	class Contact
	{
	public:
		int		Index;
		string	FirstName;
		string	LastName;
		string	Nickname;
		string	PoneNumber;
		string	DarkestSecret;
		void SetContact(string firstname, string lastname, string nickname, string phonenumber, string darkestsecret)
		{
			FirstName = firstname;
			LastName  = lastname;
			Nickname  = nickname;
			PoneNumber = phonenumber;
			DarkestSecret =darkestsecret;
		}
		//toDelete
		void ShowContact()
		{
			char tmp[45];
			tmp[44] = 0;
			memset(tmp, ' ', 44);
			tmp[10] = tmp[21] = tmp[32] = tmp[43] = '|';
			memcpy(tmp, to_string(Index).c_str(), 1);
			set_ten(tmp+11 , FirstName);
			set_ten(tmp+22 , LastName);
			set_ten(tmp+33 , Nickname);
			cout << "--------------------------------------------\n";
			cout << tmp <<endl;
		}
	};

#endif