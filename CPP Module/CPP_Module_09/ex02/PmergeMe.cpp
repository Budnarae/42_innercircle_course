#include "PmergeMe.hpp"

/* Orthodox Cannonical Form(private part) */
PmergeMe::PmergeMe() : unsortedArray(), sortedArray() {}
PmergeMe::PmergeMe(const PmergeMe &cp) : unsortedArray(), sortedArray() { (void)cp; }

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhv)
{
	(void)rhv;
	return (*this);
}

/* Private member function */
// main logic
vector<RecursivePair *>	*PmergeMe::convertIntegerToRecursivePair()
{
	vector<RecursivePair *>	*recursivePairArray = new vector<RecursivePair *>;
	
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

void	PmergeMe::convertRecursivePairToInteger()
{
	for (unsigned long i = 0; i < mainChain.size(); i++)
	{
		sortedArray.push_back(mainChain[i]->value);
		delete mainChain[i];
	}
	mainChain.clear();
}

RecursivePair	*PmergeMe::recursivelyMerge(vector<RecursivePair *> *beforeMerge, int depth)
{
	if (beforeMerge->size() == 1)
	{
		RecursivePair	*mergedArray = (*beforeMerge)[0];

		delete	beforeMerge;
		return (mergedArray);
	}
	
	vector<RecursivePair *>	*afterMerge = new vector<RecursivePair *>;

	if (beforeMerge->size() % 2 == 1)
	{
		tempChain.push_back(beforeMerge->back());
		beforeMerge->pop_back();
	}

	for (unsigned long i = 0; i < beforeMerge->size() / 2; i++)
	{
		RecursivePair	*node = new RecursivePair;

		RecursivePair	*child1 = (*beforeMerge)[2 * i];
		RecursivePair	*child2 = (*beforeMerge)[2 * i + 1];

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

vector<RecursivePair *>::iterator PmergeMe::ft_lower_bound(vector<RecursivePair *>::iterator first, \
	vector<RecursivePair *>::iterator last, RecursivePair *target)
{	
	vector<RecursivePair *>::iterator	mid;
	
	while (first < last)
	{
		mid = first + (distance(first, last) / 2);

		if ((*mid)->value < target->value)
			first = mid + 1;
		else
			last = mid;
	}

	return (first);
}

void	PmergeMe::insertPendingElememts(int prevPrevJacop, int prevJacop)
{
	int	jacop = prevJacop + prevPrevJacop * 2;
	if (static_cast<unsigned long>(jacop) > pendingElements.size())
		jacop = pendingElements.size();

	if (jacop == 1)
	{
		if (!pendingElements.empty())
			mainChain.insert(mainChain.begin(), pendingElements[0]);
	}
	else
	{
		for (int i = jacop - 1; i > prevJacop - 1; i--)
		{
			// 벡터 반복자는 삽입 연산 후 유효성을 상실하기 때문에 매번 새로 정의해야 한다.
			vector<RecursivePair *>::iterator	binarySearchRange = \
				mainChain.begin() + (prevJacop + jacop - 1);
			vector<RecursivePair *>::iterator	insertionLocation = \
				ft_lower_bound(mainChain.begin(), binarySearchRange, pendingElements[i]);
			mainChain.insert(insertionLocation, pendingElements[i]);
		}
	}

	if (static_cast<unsigned long>(jacop) == pendingElements.size())
		pendingElements.clear();
	else
		insertPendingElememts(prevJacop, jacop);
}

void			PmergeMe::recursivelyInsert()
{
	if (mainChain[0]->depth == 0)
		return ;

	for (unsigned long i = 0; i < mainChain.size(); i++)
	{
		RecursivePair	*tmp		= mainChain[i];
		RecursivePair	*largeNode	= mainChain[i]->largeNode;
		RecursivePair	*smallNode	= mainChain[i]->smallNode;

		delete tmp;

		mainChain[i] = largeNode;
		pendingElements.push_back(smallNode);
	}

	if (!tempChain.empty() && tempChain.back()->depth == mainChain[0]->depth)
	{
		pendingElements.push_back(tempChain.back());
		tempChain.pop_back();
	}
	insertPendingElememts(0, 1);
	recursivelyInsert();
}

void			PmergeMe::mergeInsertionSort()
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
PmergeMe::~PmergeMe() {}

/* Constructor */
PmergeMe::PmergeMe(const vector<int> &_unsortedArray) \
	: unsortedArray(_unsortedArray), sortedArray()
{
	mergeInsertionSort();
}

/* Public member function */
// getter
const vector<int>	&PmergeMe::getSortedArray()
{
	return (sortedArray);
}
