#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "func.hpp"

int main()
{
	Base	*b = generate();

	identify(b);
	identify(*b);
	delete b;

	return (0);
}
