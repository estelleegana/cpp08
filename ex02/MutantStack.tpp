#include "MutantStack.hpp"

//constructeur par defaut
template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << bGREEN << "MutantStack - Constructor (default) called " << RESET << std::endl;
}

//constructeur de recopie
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
	std::cout << bGREEN << "MutantStack - Constructor copy called " << RESET << std::endl;
}

//surcharge =
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	std::cout << bBLUE << "MutantStack - surcharge= called " << RESET << std::endl; (void)other; return (*this);
}

//destructeur
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << bRED << "MutantStack - Destructor called " << RESET << std::endl;
}

//
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}


template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return (this->c.rend());
}