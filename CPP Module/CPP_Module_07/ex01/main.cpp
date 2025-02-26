#include "iter.hpp"

int main()
{
	char	c_arr[3] = {'a', 'b', 'c'};
	int		i_arr[4] = {1, 2, 3, 4};
	float	f_arr[5] = {1.1f, 1.2f, 1.3f, 1.4f, 1.5f};
	double	d_arr[6] = {1.11, 2.22, 3.33, 4.44, 5.55, 6.66};

	iter(c_arr, 3, printElement<char>);
	iter(i_arr, 4, printElement<int>);
	iter(f_arr, 5, printElement<float>);
	iter(d_arr, 6, printElement<double>);

	return (0);
}