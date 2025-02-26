#ifndef PMERGEMEWithListWITHLIST_HPP
#define PMERGEMEWithListWITHLIST_HPP

#include <list>
#include <vector>
#include "structure.hpp"

using std::list;
using std::vector;
using std::iterator_traits;
using std::distance;
using std::advance;

class PmergeMeWithList
{
	private	:
		/* Private member variable */
		vector<int>	unsortedArray;
		vector<int>	sortedArray;

		list<RecursivePair *>	mainChain;
		list<RecursivePair *>	pendingElements;
		list<RecursivePair *>	tempChain;
		/* Orthodox Cannonical Form(private part) */
		PmergeMeWithList();
		PmergeMeWithList(const PmergeMeWithList &cp);
		PmergeMeWithList	&operator=(const PmergeMeWithList &rhv);
		/* Private member function */
		// main logic
		list<RecursivePair *>	*convertIntegerToRecursivePair();
		void					convertRecursivePairToInteger();
		RecursivePair			*recursivelyMerge(list<RecursivePair *> *beforeMerge, int depth = 1);
		list<RecursivePair *>::iterator ft_lower_bound(list<RecursivePair *>::iterator first, \
			list<RecursivePair *>::iterator last, RecursivePair *target);
		void					insertPendingElememts(int prevPrevJacop, int prevJacop);
		void					recursivelyInsert();
		void					mergeInsertionSort();
	public	:
		/* Orthodox Cannonical Form(public part) */
		~PmergeMeWithList();
		/* Constructor */
		PmergeMeWithList(const vector<int> &_unsortedArray);
		/* Public member function */
		// getter
		const vector<int>	&getSortedArray();
};

#endif