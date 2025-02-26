/* Orthodox Canonical Form */
template <typename T>
Array<T>::Array()
{
	arr = new T[0];
	arr_size = 0;
}

template <typename T>
Array<T>::Array(const Array<T> &cp)
{
	arr = new T[cp.arr_size];
	arr_size = cp.arr_size;
	
	for (unsigned int i = 0; i < arr_size; i++)
		arr[i] = cp.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhv)
{
	arr_size = rhv.arr_size;
	
	delete[] arr;
	arr = new T[arr_size];
	for (unsigned int i = 0; i < arr_size; i++)
		arr[i] = rhv.arr[i];
	
	return (*this);
}

/* constructor */
template <typename T>
Array<T>::Array(unsigned int n)
{
	arr_size = n;
	arr = new T[n]();
}

/* [] operator overloading */
template <typename T>
T	&Array<T>::operator[](unsigned int idx) throw (std::exception)
{
	if (idx >= arr_size)
		throw (std::exception());
	return (arr[idx]);
}

template <typename T>
T	Array<T>::operator[](unsigned int idx) const throw (std::exception)
{
	if (idx >= arr_size)
		throw (std::exception());
	return (arr[idx]);
}

/* public member function */
template <typename T>
unsigned int	Array<T>::size() const
{
	return (arr_size);
}

