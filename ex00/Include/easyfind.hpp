#pragma once

#include <exception>

template <typename T>
int easyfind(const T &container, const int index);

class OutOfBoundsException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Out of Bounds Exception");
		}
};
#include "easyfind.tpp"