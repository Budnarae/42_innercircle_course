#include "Serializer.hpp"

/* Orthodox Canonical Form(private) */
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &cp) { (void)cp; }
Serializer::~Serializer() {}
Serializer	&Serializer::operator=(const Serializer &rhv)
{
	(void)rhv;
	return (*this);
}

/* public static member function */
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}