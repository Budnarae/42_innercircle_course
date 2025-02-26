#include "Harl.hpp"

HarlFilter::HarlFilter()
{
	f[0] = &HarlFilter::debug;
	f[1] = &HarlFilter::info;
	f[2] = &HarlFilter::warning;
	f[3] = &HarlFilter::error;
}

void	HarlFilter::debug(void)
{
	cout<<"[ DEBUG ]"<<endl;
	cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."<<endl; 
	cout<<"I really do!"<<endl<<endl;
}

void	HarlFilter::info(void)
{
	cout<<"[ INFO ]"<<endl;
	cout<<"I cannot believe adding extra bacon costs more money."<<endl;
	cout<<"You didn’t put enough bacon in my burger!"<<endl;
	cout<<"If you did, I wouldn’t be asking for more!"<<endl<<endl;
}

void	HarlFilter::warning(void)
{
	cout<<"[ WARNING ]"<<endl;
	cout<<"I think I deserve to have some extra bacon for free."<<endl;
	cout<<"I’ve been coming for years whereas you started working here since last month."<<endl<<endl;
}

void	HarlFilter::error(void)
{
	cout<<"[ ERROR ]"<<endl;
	cout<<"This is unacceptable! I want to speak to the manager now."<<endl<<endl;
}

void	HarlFilter::complain(string level)
{
	string	lv_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int		index = 4;

	for (int i = 0; i < 4; i++)
	{
		if (lv_arr[i] == level)
			index = i;
	}

	switch (index)
	{
		case 0:
			(this->*f[0])();
			// fall through
		case 1:
			(this->*f[1])();
			// fall through
		case 2:
			(this->*f[2])();
			// fall through
		case 3:
			(this->*f[3])();
			break ;
		default:
			cout<<"[ Probably complaining about insignificant problems ]"<<endl;
			break ;
	}
}
