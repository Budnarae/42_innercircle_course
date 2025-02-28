#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include <cstddef>

struct RecursivePair
{
	int	depth;
	int	value;
	RecursivePair	*smallNode;
	RecursivePair	*largeNode;
};

#endif