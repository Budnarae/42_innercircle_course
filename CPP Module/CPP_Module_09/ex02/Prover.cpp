#include "Prover.hpp"

/* exception */
const char *Prover::VectorSortionFailedException::what() const throw()
{
	return ("Error : Sortion(Vector) Failed");
}

const char *Prover::ListSortionFailedException::what() const throw()
{
	return ("Error : Sortion(List) Failed");
}

/* Orthodox Cannonical Form(private part) */
Prover::Prover(const Prover &cp) { (void)cp; }

Prover	&Prover::operator=(const Prover &rhv)
{
	(void)rhv;
	return (*this);
}

void	Prover::provePmergeMe(vector<int> beforeSort, \
	vector<int> sortedByVector, vector<int> sortedByList)
{
	sort(beforeSort.begin(), beforeSort.end());

	if (beforeSort.size() != sortedByVector.size())
		throw (VectorSortionFailedException());
	if (beforeSort.size() != sortedByList.size())
		throw (ListSortionFailedException());

	for (unsigned long i = 0; i < beforeSort.size(); i++)
	{
		if (beforeSort[i] != sortedByVector[i])
			throw (VectorSortionFailedException());
		if (beforeSort[i] != sortedByList[i])
			throw (ListSortionFailedException());
	}
}

/* Orthodox Cannonical Form(public part) */
Prover::Prover() {}
Prover::~Prover() {}

/* Function Object */
void	Prover::operator()(vector<int> beforeSort, \
	vector<int> sortedByVector, vector<int> sortedByList)
{
	provePmergeMe(beforeSort, sortedByVector, sortedByList);
}