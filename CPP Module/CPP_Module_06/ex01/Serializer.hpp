#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

using	std::cout;
using	std::endl;

struct	Data
{
	int	data;
};

typedef unsigned long	uintptr_t;

class Serializer
{
	private	:
		/* Orthodox Canonical Form(private) */
		Serializer();
		Serializer(const Serializer &cp);
		~Serializer();
		Serializer	&operator=(const Serializer &rhv);
	public	:
		/* public static member function */
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif