#ifndef PROVER_HPP
#define PROVER_HPP

#include <exception>
#include <vector>
#include <algorithm>

using	std::exception;
using	std::vector;
using	std::sort;

class Prover
{
	private	:
		/* exceptions */
		class	VectorSortionFailedException : exception
		{
			const char *what() const throw();
		};
		class	ListSortionFailedException : exception
		{
			const char *what() const throw();
		};
		/* Orthodox Cannonical Form(private part) */
		Prover(const Prover &cp);
		Prover	&operator=(const Prover &rhv);
		/* key method */
		void	provePmergeMe(vector<int> beforeSort, \
			vector<int> sortedByVector, vector<int> sortedByList);
	public	:
		/* Orthodox Cannonical Form(public part) */
		Prover();
		~Prover();
		/* Function Object */
		void	operator()(vector<int> beforeSort, \
			vector<int> sortedByVector, vector<int> sortedByList);
};

#endif