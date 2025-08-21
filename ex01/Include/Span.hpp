#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
# include <algorithm>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"



class Span
{
	private:
		std::vector<int>	_vec;
		// Span();

		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "\tSpan is full" RESET);
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "\tNo span to find" RESET);
				}
		};

	public:
		// Constructors
		Span( unsigned int size );
		Span( const Span &src );

		// Destructor
		~Span();

		// Operators overload
		Span	&operator=( const Span &src );

		// Public class member functions
		void	addNumber( int n );
		void	addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		int		shortestSpan() const;
		int		longestSpan() const;

};

#endif