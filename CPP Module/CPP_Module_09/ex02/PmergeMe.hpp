#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include "structure.hpp"

using std::vector;
using std::iterator_traits;
using std::distance;

class PmergeMe
{
	private	:
		/* Private member variable */
		vector<int>	unsortedArray;
		vector<int>	sortedArray;

		vector<RecursivePair *>	mainChain;
		vector<RecursivePair *>	pendingElements;
		vector<RecursivePair *>	tempChain;
		/* Orthodox Cannonical Form(private part) */
		PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe	&operator=(const PmergeMe &rhv);
		/* Private member function */
		// main logic
		vector<RecursivePair *>	*convertIntegerToRecursivePair();
		void					convertRecursivePairToInteger();
		RecursivePair			*recursivelyMerge(vector<RecursivePair *> *beforeMerge, int depth = 1);
		vector<RecursivePair *>::iterator ft_lower_bound(vector<RecursivePair *>::iterator first, \
			vector<RecursivePair *>::iterator last, RecursivePair *target);
		void					insertPendingElememts(int prevPrevJacop, int prevJacop);
		void					recursivelyInsert();
		void					mergeInsertionSort();
	public	:
		/* Orthodox Cannonical Form(public part) */
		~PmergeMe();
		/* Constructor */
		PmergeMe(const vector<int> &_unsortedArray);
		/* Public member function */
		// getter
		const vector<int>	&getSortedArray();
};

#endif