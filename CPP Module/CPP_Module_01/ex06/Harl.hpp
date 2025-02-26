#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

class HarlFilter
{
	private :
		void	(HarlFilter::*f[4])(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public :
		HarlFilter();
		void	complain(string level);
};

#endif