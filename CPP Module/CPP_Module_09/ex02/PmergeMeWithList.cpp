#include "PmergeMeWithList.hpp"

/* Orthodox Cannonical Form(private part) */
PmergeMeWithList::PmergeMeWithList() : unsortedArray(), sortedArray() {}
PmergeMeWithList::PmergeMeWithList(const PmergeMeWithList &cp) : unsortedArray(), sortedArray() { (void)cp; }

PmergeMeWithList	&PmergeMeWithList::operator=(const PmergeMeWithList &rhv)
{
	(void)rhv;
	return (*this);
}

/* Private member function */
// main logic
list<RecursivePair *>	*PmergeMeWithList::convertIntegerToRecursivePair()
{
	list<RecursivePair *>	*recursivePairArray = new list<RecursivePair *>;
	
	if (unsortedArray.size() % 2 == 1)
	{
		RecursivePair	*node = new RecursivePair;

		node->depth		= 0;
		node->value		= unsortedArray.back();

		unsortedArray.pop_back();

		node->smallNode	= NULL;
		node->largeNode	= NULL;

		tempChain.push_back(node);
	}
	for (unsigned long i = 0; i < unsortedArray.size(); i++)
	{
		RecursivePair	*node = new RecursivePair;

		node->depth		= 0;
		node->value		= unsortedArray[i];
		node->smallNode	= NULL;
		node->largeNode	= NULL;

		recursivePairArray->push_back(node);
	}

	return (recursivePairArray);
}

void	PmergeMeWithList::convertRecursivePairToInteger()
{
	for (list<RecursivePair *>::iterator iter = mainChain.begin(); iter != mainChain.end(); iter++)
	{
		sortedArray.push_back((*iter)->value);
		delete *iter;
	}
	mainChain.clear();
}

RecursivePair	*PmergeMeWithList::recursivelyMerge(list<RecursivePair *> *beforeMerge, int depth)
{
	if (beforeMerge->size() == 1)
	{
		RecursivePair	*mergedArray = (*beforeMerge).front();

		delete	beforeMerge;
		return (mergedArray);
	}
	
	list<RecursivePair *>	*afterMerge = new list<RecursivePair *>;

	if (beforeMerge->size() % 2 == 1)
	{
		tempChain.push_back(beforeMerge->back());
		beforeMerge->pop_back();
	}

	while (!(*beforeMerge).empty())
	{
		RecursivePair	*node = new RecursivePair;

		RecursivePair	*child1 = (*beforeMerge).front();
		(*beforeMerge).pop_front();
		RecursivePair	*child2 = (*beforeMerge).front();
		(*beforeMerge).pop_front();

		node->depth = depth;
		if (child1->value <= child2->value)
		{
			node->smallNode	= child1;
			node->largeNode	= child2;
			node->value		= child2->value;
		}
		else
		{
			node->smallNode	= child2;
			node->largeNode	= child1;
			node->value		= child1->value;
		}

		afterMerge->push_back(node);
	}

	delete beforeMerge;
	return (recursivelyMerge(afterMerge, depth + 1));
}

list<RecursivePair *>::iterator PmergeMeWithList::ft_lower_bound(list<RecursivePair *>::iterator first, \
	list<RecursivePair *>::iterator last, RecursivePair *target)
{	
	list<RecursivePair *>::iterator	mid;
	
	while (distance(first, last) > 0)
	{
		mid = first; 
		advance(mid, distance(first, last) / 2);

		if ((*mid)->value < target->value)
			first = ++mid;
		else
			last = mid;
	}

	return (first);
}

void	PmergeMeWithList::insertPendingElememts(int prevPrevJacop, int prevJacop)
{
	int	jacop = prevJacop + prevPrevJacop * 2;
	if (static_cast<unsigned long>(jacop) > pendingElements.size())
		jacop = pendingElements.size();

	if (jacop == 1)
	{
		if (!pendingElements.empty())
			mainChain.insert(mainChain.begin(), pendingElements.front());
	}
	else
	{
		for (int i = jacop - 1; i > prevJacop - 1; i--)
		{
			list<RecursivePair *>::iterator	binarySearchRange = mainChain.begin();
			advance(binarySearchRange, prevJacop + jacop - 1);
			list<RecursivePair *>::iterator	targetPosition = pendingElements.begin();
			advance(targetPosition, i);
			list<RecursivePair *>::iterator	insertionLocation = \
				ft_lower_bound(mainChain.begin(), binarySearchRange, *targetPosition);
			mainChain.insert(insertionLocation, *targetPosition);
		}
	}

	if (static_cast<unsigned long>(jacop) == pendingElements.size())
		pendingElements.clear();
	else
		insertPendingElememts(prevJacop, jacop);
}

void			PmergeMeWithList::recursivelyInsert()
{
	if (mainChain.front()->depth == 0)
		return ;

	for (list<RecursivePair *>::iterator iter = mainChain.begin(); iter != mainChain.end(); iter++)
	{
		RecursivePair	*tmp		= *iter;
		RecursivePair	*largeNode	= (*iter)->largeNode;
		RecursivePair	*smallNode	= (*iter)->smallNode;

		delete tmp;

		*iter = largeNode;
		pendingElements.push_back(smallNode);
	}

	if (!tempChain.empty() && tempChain.back()->depth == mainChain.front()->depth)
	{
		pendingElements.push_back(tempChain.back());
		tempChain.pop_back();
	}
	insertPendingElememts(0, 1);
	recursivelyInsert();
}

void			PmergeMeWithList::mergeInsertionSort()
{
	// 크기가 1인 배열은 정렬이 필요 없음.
	if (unsortedArray.size() == 1)
	{
		sortedArray = unsortedArray;
		return ;
	}

	RecursivePair	*mergedArray = \
		recursivelyMerge(convertIntegerToRecursivePair(), 1);
	mainChain.push_back(mergedArray);
	recursivelyInsert();
	convertRecursivePairToInteger();
}

/* Orthodox Cannonical Form(public part) */
PmergeMeWithList::~PmergeMeWithList() {}

/* Constructor */
PmergeMeWithList::PmergeMeWithList(const vector<int> &_unsortedArray) \
	: unsortedArray(_unsortedArray), sortedArray()
{
	mergeInsertionSort();
}

/* Public member function */
// getter
const vector<int>	&PmergeMeWithList::getSortedArray()
{
	return (sortedArray);
}
