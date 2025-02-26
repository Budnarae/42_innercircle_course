#include "crappyPhonebook.hpp"

//-----General_Func-----

bool	checkStringAlpha(string s)
{
	if (s.length() == 0)
		return (0);

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (isalpha(s[i]) == 0)
			return (0);
	}

	return (1);
}

bool	checkStringDigit(string s)
{
	if (s.length() == 0)
		return (0);

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}

//-----Contact-----

void	Contact::clearContact()
{
	firstName.clear();
	lastName.clear();
	nickName.clear();
	phoneNumber.clear();
	darkestSecret.clear();

	return ;
}

void	Contact::setFirstName()
{
	while (1)
	{
		cout<<"FirstName : ";
		getline(cin, firstName);

		if (cin.eof())
		{
			cout<<"EOF found. End the program."<<endl;
			exit(0);
		}

		if (checkStringAlpha(firstName) == 0)
		{
			cout<<"Wrong name format."<<endl;
			firstName.clear();
		}
		else
			break;
	}

	return ;
}

void	Contact::setLastName()
{
	while (1)
	{
		cout<<"LastName : ";
		getline(cin, lastName);

		if (cin.eof())
		{
			cout<<"EOF found. End the program."<<endl;
			exit(0);
		}

		if (checkStringAlpha(lastName) == 0)
		{
			cout<<"Wrong name format."<<endl;
			lastName.clear();
		}
		else
			break;
	}

	return ;
}

void	Contact::setNickName()
{
	while (1)
	{
		cout<<"NickName : ";
		getline(cin, nickName);

		if (cin.eof())
		{
			cout<<"EOF found. End the program."<<endl;
			exit(0);
		}

		if (checkStringAlpha(nickName) == 0)
		{
			cout<<"Wrong name format."<<endl;
			nickName.clear();
		}
		else
			break;
	}

	return ;
}

void	Contact::setPhoneNumber()
{
	while (1)
	{
		cout<<"PhoneNumber : ";
		getline(cin, phoneNumber);

		if (cin.eof())
		{
			cout<<"EOF found. End the program."<<endl;
			exit(0);
		}

		if (checkStringDigit(phoneNumber) == 0)
		{
			cout<<"Phonenumber should be a numeric."<<endl;
			phoneNumber.clear();
		}
		else
			break;
	}

	return ;
}

void	Contact::setDarkestSecret()
{
	cout<<"Darkest Secret : ";
	getline(cin, darkestSecret);

	if (cin.eof())
	{
		cout<<"EOF found. End the program."<<endl;
		exit(0);
	}

	return ;
}

void	Contact::printField(string field)
{

	if(field.length() < 10)
	{
		cout<<std::setw(10);
		cout<<field;
	}
	else
	{
		string tmp = field.substr(0, 9);
		cout<<tmp<<".";
	}

	return ;
}

void	Contact::setContact()
{
	setFirstName();
	setLastName();
	setNickName();
	setPhoneNumber();
	setDarkestSecret();

	return ;
}

void	Contact::printPartialContact(string index)
{
	cout<<'|';
	printField(index);
	cout<<"|";
	printField(firstName);
	cout<<"|";
	printField(lastName);
	cout<<"|";
	printField(nickName);
	cout<<"|";
	cout<<endl;
}

void	Contact::printFullContact()
{
	cout<<"firstName : "<<firstName<<endl;
	cout<<"lastName : "<<lastName<<endl;
	cout<<"nickName : "<<nickName<<endl;
	cout<<"phoneNumber : "<<phoneNumber<<endl;
	cout<<"darkestSecret : "<<darkestSecret<<endl;
}

//-----Phonebook-----

Phonebook::Phonebook()
{
	cursor = 0;
}

void	Phonebook::execPhonebook()
{
	string	command;

	while (command != "EXIT")
	{
		cout<<"Input command : ";
		getline(cin, command);
		
		cout<<endl;

		if (cin.eof())
		{
			cout<<"EOF found. End the program."<<endl;
			exit(0);
		}
		else if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
		else if (command == "EXIT")
			cout<<"Exit crappyPhonebook"<<endl;
		else
			cout<<"Wrong command. Please input command again."<<endl;
		
		cout<<endl;
	}

	return ;
}

void	Phonebook::addContact()
{
	cont[cursor].clearContact();
	cont[cursor].setContact();

	cursor = (cursor + 1) % 8;
	
	return ;
}

void	Phonebook::printAllContact()
{
	string	index = "0";

	cout<<"|     index|first name| last name|  nickname|"<<endl;
	cout<<"+----------+----------+----------+----------+"<<endl;

	while (index[0] < '8')
	{
		cont[(int)(index[0] - '0')].printPartialContact(index);
		index[0] += 1;
	}
	cout<<endl;
}

void	Phonebook::searchContact()
{
	string	index;

	while (1)
	{
		printAllContact();
	
		cout<<"Index of contact : ";
		getline(cin, index);

		if (cin.eof())
		{
			cout<<"EOF found. End the program."<<endl;
			exit(0);
		}	
		else if (checkStringDigit(index) == false \
			|| std::atoi(index.c_str()) < 0 || std::atoi(index.c_str()) > 7)
			cout<<"Index should be a number (0 <= index <= 7)"<<endl;
		else
			break;
	}

	cout<<endl;
	cont[(int)(index[0] - '0')].printFullContact();

	return ;
}
