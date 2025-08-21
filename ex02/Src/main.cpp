#include "../Include/MutantStack.hpp"

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



void	main_list()
{
	std::list<int> l;

	for (int i = 0; i < 100; i++)
	{
		l.push_back(i);
	}
	sub_title("After adding 100 elements to list back");
	std::cout << "\tOn top: " << l.back() << std::endl;
	std::cout << "\tSize: " << l.size() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 90; i++)
		l.pop_back();
	sub_title("After pop_back 90");
	std::cout << "\tOn top: " << l.back() << std::endl;
	std::cout << "\tSize: " << l.size() << std::endl;
	std::cout << std::endl;

	sub_title("Iterating (displaying from begin to end)");
	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "\t" << *it << std::endl;
		++it;
	}
	std::list<int> s(l);
}



void	main_mutant()
{
	MutantStack<int> mstack;

	for (int i = 0; i < 100; i++)
	{
		mstack.push(i);
	}
	sub_title("After adding 100 elements to mstack");
	std::cout << "\tOn top: " << mstack.top() << std::endl;
	std::cout << "\tSize: " << mstack.size() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 90; i++)
		mstack.pop();
	sub_title("After pop 90");
	std::cout << "\tOn top: " << mstack.top() << std::endl;
	std::cout << "\tSize: " << mstack.size() << std::endl;
	std::cout << std::endl;

	sub_title("Iterating (displaying from begin to end)");
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "\t" << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}



int	main(void)
{
	title("MUTANT STACK");
	main_mutant();

	title("LIST");
	main_list();

	return (0);
}
