#pragma once
#include <vector>

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
		class FullException : public std::exception
		{
			virtual const char* what() const throw();
		};
};