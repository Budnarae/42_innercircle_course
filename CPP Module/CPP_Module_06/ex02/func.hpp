#ifndef FUNC_HPP
#define FUNC_HPP

#include <ctime>
#include <cstdlib>
#include <typeinfo>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
