#include "Span.hpp"

Span::Span() : _sizeMax(0)
{}

Span::Span(unsigned int N) : _sizeMax(N)
{}

Span::Span(const Span &copy) : _sizeMax(copy._sizeMax), _numbers(copy._numbers)
{}

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
		return ("not enough numbers to calculate any span");
	
}

const char *Span::FullException::what() const throw()
{
	return ("max numbers reached: ");
}