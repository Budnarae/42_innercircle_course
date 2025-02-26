#include <iostream>
#include <iomanip>
#include <ctime>
#include "PmergeMe.hpp"
#include "PmergeMeWithList.hpp"
#include "InputArrayParser.hpp"
#include "NoneInputException.hpp"
#include "Prover.hpp"

using	std::cout;
using	std::endl;
using	std::clock_t;
using	std::clock;

/*
void	checkLeaks()
{
	system("leaks PmergeMe");
}
*/

int main(int argc, char **argv)
{
	//atexit(checkLeaks);

	try
	{
		if (argc < 2)
			throw (NoneInputException());

		InputArrayParser	inputArrayParser(argv);
		vector<int>			beforeSort = inputArrayParser.getParsedArray();

		clock_t	sortionStart;
		clock_t	sortionEnd;
		double	vectorSortionSpeed;
		double	listSortionSpeed;

		sortionStart = clock();
		PmergeMe			sorterUsingVector(beforeSort);
		vector<int>			sortedByVector = sorterUsingVector.getSortedArray();
		sortionEnd = clock();
		vectorSortionSpeed = sortionEnd - sortionStart;

		sortionStart = clock();
		PmergeMeWithList	sorterUsingList(beforeSort);
		vector<int>			sortedByList = sorterUsingList.getSortedArray();
		sortionEnd = clock();
		listSortionSpeed = sortionEnd - sortionStart;

		cout << "before: ";
		for (unsigned long i = 0; i < beforeSort.size(); i++)
			cout << beforeSort[i] << " ";
		cout << endl;

		cout << "after:  ";
		for (unsigned long i = 0; i < sortedByVector.size(); i++)
			cout << sortedByVector[i] << " ";
		cout << endl;

		cout << std::fixed << std::setprecision(0);
		cout << "Time to process a range of " << beforeSort.size() << " elements with std::vector : " << vectorSortionSpeed << " us" << endl;
		cout << "Time to process a range of " << beforeSort.size() << " elements with std::list   : " << listSortionSpeed << " us" << endl;

		Prover	prover;
		prover(beforeSort, sortedByVector, sortedByList);
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
		return (1);
	}
}
