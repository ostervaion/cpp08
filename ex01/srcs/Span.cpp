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

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_list.size() + std::distance(begin, end) > _max)
		throw NoSpaceLeftInSpanException();
	_list.insert(_list.end(), begin, end);
}

int	Span::shortestSpan()
{
	int	prev = 0;
	int span = 0;

	if (_list.size() < 2)
		throw NoSpanFoundException();
	std::sort(_list.begin(), _list.end());
	span = _list[1] - _list[0];
	prev = _list[1];
	for (unsigned long i = 2; i < _list.size() ; i++)
	{
		if (_list[i] - prev < span)
			span = _list[i] - prev;
		prev = _list[i];
	}
	return (span);
}

int	Span::longestSpan()
{
	if (_list.size() < 2)
		throw NoSpanFoundException();
	std::sort(_list.begin(), _list.end());
	return (_list.back() - _list.front());
}

const char *Span::NoSpaceLeftInSpanException::what() const throw()
{
	return ("There is no space for more numbers");
}

const char *Span::NoSpanFoundException::what() const throw()
{
	return ("There is not enough numbers to show the span");
}