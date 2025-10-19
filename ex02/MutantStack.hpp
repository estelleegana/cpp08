#pragma once

#include <iostream>
#include <stack>
#include <vector>

#define bGREEN "\033[1;32m"
#define bRED "\033[1;31m"
#define bYELLOW "\033[1;33m"
#define bBLUE "\033[1;34m"
#define RESET "\033[1;0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		//pas besoin de surcharger les pop, push, top etc.. 
		//puisque mstack herite de std::stack

		//typename car c un type dependant d'un template
		//std::stack<T>::container_type : type du container sous-jacent std::deque<T>
		//::iterator : type d'iterateur du container deque
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin() const;
		const_iterator cend() const;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

};