#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

class Harl
{
	private :
		void	(Harl::*f[4])(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
		Harl();
		void	complain(string level);
};

#endif