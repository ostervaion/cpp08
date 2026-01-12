#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
	try
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		std::cout << *easyfind(v, 4) << std::endl;
		std::cout << *easyfind(v, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int> dq;
		dq.push_back(1);
		dq.push_back(2);
		dq.push_back(3);
		dq.push_back(4);
		std::cout << *easyfind(dq, 1) << std::endl;
		std::cout << *easyfind(dq, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		std::cout << *easyfind(lt, 2) << std::endl;
		std::cout << *easyfind(lt, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}