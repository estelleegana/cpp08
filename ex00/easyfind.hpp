#pragma once

#include <algorithm>//std::find
#include <iostream>

// class DoesNotExist : public std::exception
// {
// 	public:
// 		virtual const char* what() const throw()
// 		{
// 			return "value not found in container";
// 		}
// };

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		std::cerr << "Error: value not found in container";
		// throw DoesNotExist();
	return it;
}

//std::find cherche 1 valeur ds une plage d'elem
//find(ptr vers 1er elem, ptr hors limite apres dernier elem, elem recherche)
//renvoie le ptr hors limite si rien trouve