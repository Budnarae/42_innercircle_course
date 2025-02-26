#include <iostream>
#include <list>
#include "MutantStack.tpp"

using std::cout;
using std::endl;
using std::list;

int main()
{
	{
		cout << "Testing Mutant Stack" << endl;
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		cout << mstack.top() << endl;

		mstack.pop();

		cout << mstack.size() << endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			cout << *it << endl;
			++it;
		}
		
		std::sort(mstack.begin(), mstack.end());
		for (MutantStack<int>::iterator iter = mstack.begin(); iter != mstack.end(); iter++)
		{
			cout << *iter << endl;
		}

		std::stack<int> s(mstack);
	}
	{
		cout << "Compare with List" << endl;
		std::list<int>	lst;

		lst.push_back(5);
		lst.push_back(17);

		cout << lst.back() << endl;

		lst.pop_back();

		cout << lst.size() << endl;
		
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		list<int>::iterator	it = lst.begin();
		list<int>::iterator	ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			cout << *it << endl;
			++it;
		}

		lst.sort();
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
		{
			cout << *iter << endl;
		}
	}
	{
		cout << "Testing Copying" << endl;

		MutantStack<int>	ms;
		MutantStack<int>	ms2;

		ms2.push(5);
		ms2.push(7);
		ms2.push(8);

		ms = ms2;

		for (MutantStack<int>::iterator	iter = ms.begin(); iter != ms.end(); iter++)
			cout << (*iter) << endl;
	}

	return (0);
}