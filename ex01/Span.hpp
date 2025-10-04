#pragma once
#include <vector>
#include <algorithm>//std::sort
#include <iostream>//cout endl
#include <limits>//std::numeric_limits<int>::max() et min() soit 2147483647 et -2147483648
// #include <exception>

// template<typename T>
class Span
{
	private:
		unsigned int _sizeMax;
		std::vector<int> _numbers;
	public:
		//constructeurs
		Span();//defaut
		Span(unsigned int N);//1 parametre
		Span(const Span &copy);//de recopie

		//destructeur
		~Span();

		//affectation
		Span &operator=(const Span &other);
		
		//fonctions membres
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		//exceptions
		struct FullException : public std::exception
		{
			virtual const char* what() const throw();
		};

		struct NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
};