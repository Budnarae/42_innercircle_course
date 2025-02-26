#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

struct RecursivePair
{
	int	depth;
	int	value;
	RecursivePair	*smallNode;
	RecursivePair	*largeNode;
};

#endif