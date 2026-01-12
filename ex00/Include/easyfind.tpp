#pragma once

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int index)
{
	typename T::iterator it = std::find(container.begin(), container.end(), index);
	if (it == container.end())
		throw NumberNotFound();
	return (it);
	/* 
	if (static_cast<int>(container.size()) <= index || index < 0)
		throw OutOfBoundsException();
	typename T::const_iterator iter = container.begin();
	for (int i = 0; i != index; i++)
		iter++;
	return (*iter); */
}