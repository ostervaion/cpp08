#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::cout << "=== Span Class Tests ===" << std::endl;
	try
	{
		// Test 1: Basic functionality
		std::cout << "\n--- Test 1: Basic span with 5 elements ---" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	// Test 2: Single element (should throw)
	try
	{
		std::cout << "\n--- Test 2: Single element ---" << std::endl;
		Span sp2 = Span(1);
		sp2.addNumber(42);
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 3: Adding too many numbers (should throw)
	std::cout << "\n--- Test 3: Overflow ---" << std::endl;
	Span sp3 = Span(2);
	sp3.addNumber(1);
	sp3.addNumber(2);
	try
	{
		sp3.addNumber(3);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	// Test 4: Large span
	try
	{
		std::cout << "\n--- Test 4: Large span with 10000 elements ---" << std::endl;
		Span sp4 = Span(10000);
		std::vector<int> vect;
		std::srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			vect.push_back(std::rand());
		}
		sp4.addNumber(vect.begin(), vect.end());
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}