#pragma once

#include "easyfind.hpp"

template <typename T>
int easyfind(const T &container, const int index)
{
	if (static_cast<int>(container.size()) <= index || index < 0)
		throw OutOfBoundsException();
	typename T::const_iterator iter = container.begin();
	for (int i = 0; i != index; i++)
		iter++;
	return (*iter);
}