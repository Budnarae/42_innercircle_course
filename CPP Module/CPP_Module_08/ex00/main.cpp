#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;

int main()
{
	vector<int>	vec(10);

	for (int i = 0; i < 10; i++)
		vec.at(i) = i;
	
	vector<int>::iterator	vecIter = easyfind(vec, 7);
	cout << *vecIter << endl;

	try
	{
		vecIter = easyfind(vec, 11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	deque<int>	deq(10);

	for (int i = 0; i < 10; i++)
		deq.at(i) = i + 10;
	
	deque<int>::iterator	deqIter = easyfind(deq, 13);
	cout << *deqIter << endl;

	try
	{
		deqIter = easyfind(deq, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	list<int>	lst;

	for (int i = 20; i < 30; i++)
		lst.push_back(i);
	
	list<int>::iterator		lstIter = easyfind(lst, 20);
	cout << *lstIter << endl;

	try
	{
		lstIter = easyfind(lst, -5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
