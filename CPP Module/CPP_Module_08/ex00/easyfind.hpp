#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int target) throw (std::invalid_argument)
{
	typename T::iterator	iter;

	iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end())
		throw (std::invalid_argument(std::string("Error : There's no such value in that container.")));
	return (iter);
}

#endif
