#include "Harl.hpp"

Harl::Harl()
{
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
}

void	Harl::debug(void)
{
	cout<<"[ DEBUG ]"<<endl;
	cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."<<endl; 
	cout<<"I really do!"<<endl;
}

void	Harl::info(void)
{
	cout<<"[ INFO ]"<<endl;
	cout<<"I cannot believe adding extra bacon costs more money."<<endl;
	cout<<"You didn’t put enough bacon in my burger!"<<endl;
	cout<<"If you did, I wouldn’t be asking for more!"<<endl;
}

void	Harl::warning(void)
{
	cout<<"[ WARNING ]"<<endl;
	cout<<"I think I deserve to have some extra bacon for free."<<endl;
	cout<<"I’ve been coming for years whereas you started working here since last month."<<endl;
}

void	Harl::error(void)
{
	cout<<"[ ERROR ]"<<endl;
	cout<<"This is unacceptable! I want to speak to the manager now."<<endl;
}

void	Harl::complain(string level)
{
	string	lv_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (lv_arr[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}

	cout<<"[ Probably complaining about insignificant problems ]"<<endl;
	return ;
}