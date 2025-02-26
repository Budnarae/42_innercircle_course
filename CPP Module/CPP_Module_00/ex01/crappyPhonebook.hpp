#ifndef CRAPPYPHONEBOOK_HPP
#define CRAPPYPHONEBOOK_HPP

#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::isalpha;
using std::isdigit;

class Contact
{
	private :
		string	firstName;
		string	lastName;
		string	nickName;
		string	phoneNumber;
		string	darkestSecret;
		void	setFirstName();
		void	setLastName();
		void	setNickName();
		void	setPhoneNumber();
		void	setDarkestSecret();
		void	printField(string field);
	public :
		void	clearContact();
		void	setContact();
		void	printPartialContact(string index);
		void	printFullContact();
};

class Phonebook
{
	private :
		Contact cont[8];
		int		cursor;
		void	addContact();
		void	printAllContact();
		void	searchContact();
	public :
		Phonebook();
		void	execPhonebook();
};

bool	checkStringAlpha(string s);
bool	checkStringDigit(string s);

#endif