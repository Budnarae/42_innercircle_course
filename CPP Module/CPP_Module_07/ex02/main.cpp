#include "Array.hpp"

int main( void )
{
	Array<char>		c_arr;
	Array<int>		i_arr(3);
	
	i_arr[0] = 4;
	i_arr[1] = 2;
	i_arr[2] = 4;

	Array<int>		i_arr2(3);
	i_arr2 = i_arr;
	Array<int>		i_arr3(i_arr2);

	Array<long>		l_arr(5);

	Array<double>	d_arr(4);
	d_arr[0] = 4.4;
	d_arr[1] = 2.2;
	d_arr[2] = 4.4;
	d_arr[3] = 2.2;

	try
	{
		c_arr[0] = 'a';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		d_arr[4] = 6.6;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	cout << i_arr[0] << endl;
	cout << i_arr[1] << endl;
	cout << i_arr[2] << endl;

	cout << endl;

	cout << i_arr2[0] << endl;
	cout << i_arr2[1] << endl;
	cout << i_arr2[2] << endl;

	cout << endl;

	cout << i_arr3[0] << endl;
	cout << i_arr3[1] << endl;
	cout << i_arr3[2] << endl;

	cout << endl;

	cout << l_arr[0] << endl;
	cout << l_arr[1] << endl;
	cout << l_arr[2] << endl;
	cout << l_arr[3] << endl;
	cout << l_arr[4] << endl;

	cout << endl;

	cout << d_arr[0] << endl;
	cout << d_arr[1] << endl;
	cout << d_arr[2] << endl;
	cout << d_arr[3] << endl;

	cout << endl;

	const Array<int>	emptyArr(4);

	//emptyArr[0] = 10; // <- error!

	cout << emptyArr[0] << endl;
	cout << emptyArr[1] << endl;
	cout << emptyArr[2] << endl;
	cout << emptyArr[3] << endl;
}