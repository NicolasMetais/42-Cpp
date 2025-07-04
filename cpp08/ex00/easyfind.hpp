#pragma once
#include <iostream>
#include <vector>

template <typename T>
int easyfind(T container, int find)
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator end = container.end();

	for (; it !=end; ++it)
	{
		if (*it == find)
			return *it;
	}
	throw std::runtime_error("not found");
};