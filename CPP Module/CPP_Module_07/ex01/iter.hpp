#ifndef ITER
#define ITER

#include <iostream>

using	std::cout;
using	std::endl;

template <typename T1, typename T2>
void	iter(T1 *arr, unsigned int arr_len, T2 func_ptr)
{
	for (unsigned int i = 0; i < arr_len; i++)
		func_ptr(arr[i]);
}

template <typename T>
void	printElement(T arr)
{
	cout << arr << endl;
}

#endif
