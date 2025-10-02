#pragma once

#include <algorithm>//std::find

class DoesNotExist : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "value not found in container";
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw DoesNotExist();
	return it;
}