#pragma once

#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(const T &container, const int index);

class NumberNotFound : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Number not found exception");
		}
};
#include "easyfind.tpp"