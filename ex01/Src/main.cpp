#include "../Include/Span.hpp"
#define SIZE 100000

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << "\tshortest span = " << sp.shortestSpan() << std::endl;
// 	std::cout << "\tlongest span  = " << sp.longestSpan() << std::endl;

// 	return 0;
// }

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




void	main_adding_numbers(Span &sp)
{
	try
	{
		sub_title("Adding numbers to full capacity");
		for (int i = 0; i < SIZE; i++)
			sp.addNumber(std::rand());
		std::cout << std::endl;


		sub_title("Trying to add a number in a span that is already full");
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
}



void	main_spans(Span &sp)
{
	sub_title("Shoretest span");
	try
	{
		int	shortest = sp.shortestSpan();
		std::cout << "\tshortest span = " << shortest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	sub_title("Longest span");
	try
	{
		int	longest = sp.longestSpan();
		std::cout << "\tlongest span  = " << longest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}



void	main_add_vector(Span &sp)
{
	sub_title("Create a vector that contain SIZE int");
	std::vector<int> v;
	for (int i = 0; i < SIZE; i++)
		v.push_back(std::rand());
	std::cout << std::endl;

	sub_title("Try adding vector to span");
	try
	{
		sp.addVector(v);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	sub_title("Try adding another vector to span (but it's already full)");
	try
	{
		sp.addVector(v);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
}


int	main(void)
{
	srand(time(NULL));

	title("CREATE A SPAN");
	Span	sp1 = Span(SIZE);
	std::cout << std::endl;

	title("ADDING NUMBERS");
	main_adding_numbers(sp1);

	title("GET SHORTEST AND LONGEST SPANS");
	main_spans(sp1);

	title("CREATE NEW SPAN");
	Span	sp2 = Span(SIZE);
	std::cout << std::endl;

	title("ADDING NUMBERS FROM A VECTOR");
	main_add_vector(sp2);

	title("GET SHORTEST AND LONGEST SPANS");
	main_spans(sp2);

	title("DESTROYING SPANS");
	return (0);
}
