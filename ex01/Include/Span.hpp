#pragma once

#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
class Span
{
	private:
		unsigned int _max;
		std::vector<int> _list;

	public:
		Span(unsigned int N);
		Span();
		Span(const Span &other);
		~Span();
		Span	&operator=(const Span &other);
		void	addNumber(const int num);
		template<typename T>
		void	addNumber(T begin, T end);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int	shortestSpan();
		int	longestSpan();

	class NoSpanFoundException : public  std::exception
	{
		virtual const char *what() const throw();
	};
	
	class NoSpaceLeftInSpanException : public  std::exception
	{
		virtual const char *what() const throw();
	};
};

template<typename T>
void	Span::addNumber(T begin, T end)
{
	while (begin != end)
	{
		if (_list.size() >= _max)
			throw NoSpaceLeftInSpanException();
		_list.push_back(*begin);
		begin++;
	}
}