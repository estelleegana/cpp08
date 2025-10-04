#include "Span.hpp"

Span::Span() : _sizeMax(0)
{}

Span::Span(unsigned int N) : _sizeMax(N)
{}

Span::Span(const Span &copy) : _sizeMax(copy._sizeMax), _numbers(copy._numbers)
{}

Span& Span::operator=(const Span &other)
{
	if (this != &other)//protection contre l'autoaffectation
	{
		_numbers = other._numbers;
		_sizeMax = other._sizeMax;
	}
	return (*this);//objet courant
}

Span::~Span()
{}

void Span::addNumber(int newNumber)
{
	if (_numbers.size() == _sizeMax)
		throw FullException();
	else
		_numbers.push_back(newNumber);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	else
	{
		std::sort(_numbers.begin(), _numbers.end());
		int minSpan = std::numeric_limits<int>::max();//2147483647
		// int diff = _numbers[1] - _numbers[0];
		for (size_t i = 1; i < _numbers.size(); i++)
		{
			int diff = _numbers[i] - _numbers[i - 1];
			if (diff < minSpan)
				minSpan = diff;
		}
		return minSpan;
	}
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	else
	{
		std::sort(_numbers.begin(), _numbers.end());
		return (_numbers[_numbers.size() - 1] - _numbers[0]);
	}
}

const char *Span::NoSpanException::what() const throw()
{
	return ("no span");
}

const char *Span::FullException::what() const throw()
{
	return ("max numbers reached: ");
}