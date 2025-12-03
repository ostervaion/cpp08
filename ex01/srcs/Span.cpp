#include "Span.hpp"

Span::Span(unsigned int N) : _max(N)
{

}

Span::Span() : _max(0)
{

}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{

}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_max = other._max;
		this->_list = other._list;
	}
	return (*this);
}

void	Span::addNumber(const int num)
{
	if (_list.size() < _max)
		_list.push_back(num);
	else
		throw NoSpaceLeftInSpanException();
}

int	Span::shortestSpan()
{
	int	prev = 0;
	int span = 0;

	if (_list.size() < 2)
		throw NoSpanFoundException();
	std::vector<int> aux = _list;
	std::sort(aux.begin(), aux.end());
	std::vector<int>::iterator iter = aux.begin();
	prev = *iter;
	iter++;
	span = *iter - prev;
	prev = *iter;
	iter++;
	for (unsigned long i = 2; i < _list.size() ; i++)
	{
		if (*iter - prev < span)
			span = *iter - prev;
		prev = *iter;
		iter++;
	}
	return (span);
}

int	Span::longestSpan()
{
	int	smallest = 0;
	int largest	 = 0;

	if (_list.size() < 2)
		throw NoSpanFoundException();
	std::vector<int>::iterator iter =_list.begin();
	smallest = *iter;
	iter++;
	if (*iter >= smallest)
		largest = *iter;
	else
	{
		largest = smallest;
		smallest = *iter;
	}
	iter++;
	for (unsigned long i = 2; i < _list.size() ; i++)
	{
		if (smallest > *iter)
			smallest = *iter;
		else if(largest < *iter)
			largest = *iter;
		iter++;
	}
	return (largest - smallest);
}

const char *Span::NoSpaceLeftInSpanException::what() const throw()
{
	return ("There is no space for more numbers");
}

const char *Span::NoSpanFoundException::what() const throw()
{
	return ("There is not enough numbers to show the span");
}