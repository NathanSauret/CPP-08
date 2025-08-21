#include "../Include/easyfind.hpp"

void	title(const std::string str)
{
	std::string	title;
	if (str.length() + 2 >= 42)
		return ;
	title.append(" " + str + " ");
	while (title.length() < 42)
		title.append("~");
	std::cout << YELLOW << title << RESET << std::endl;
}

void	sub_title(const std::string str)
{
	std::string	title;
	title.append("        ~~~ " + str + " ");
	while (title.length() < 42)
		title.append("~");
	std::cout << CYAN << title << RESET << std::endl;
}



void	main_vector()
{
	sub_title("Putting '42' and '256' in a vector");
	std::vector<int> v;
	v.push_back(42);
	std::cout << "\tv.push_back(42) done" << std::endl;
	v.push_back(256);
	std::cout << "\tv.push_back(256) done" << std::endl;

	try
	{
		sub_title("Easyfind 42");
		easyfind(v, 42);
		sub_title("Easyfind 256");
		easyfind(v, 256);
		sub_title("Easyfind 404");
		easyfind(v, 404);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}


void	main_list()
{
	sub_title("Putting '42' and '256' in a list");
	std::list<int> l;
	l.push_back(42);
	std::cout << "\tl.push_back(42) done" << std::endl;
	l.push_back(256);
	std::cout << "\tl.push_back(256) done" << std::endl;

	try
	{
		sub_title("Easyfind 42");
		easyfind(l, 42);
		sub_title("Easyfind 256");
		easyfind(l, 256);
		sub_title("Easyfind 404");
		easyfind(l, 404);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}



void	main_deque()
{
	sub_title("Putting '42' and '256' in a deque");
	std::deque<int> d;
	d.push_back(42);
	std::cout << "\td.push_back(42) done" << std::endl;
	d.push_back(256);
	std::cout << "\td.push_back(256) done" << std::endl;

	try
	{
		sub_title("Easyfind 42");
		easyfind(d, 42);
		sub_title("Easyfind 256");
		easyfind(d, 256);
		sub_title("Easyfind 404");
		easyfind(d, 404);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}



int	main(void)
{
	title("TESTING WITH VECTORS");
	main_vector();

	title("TESTING WITH LISTS");
	main_list();

	title("TESTING WITH DEQUES");
	main_deque();

	return (0);
}