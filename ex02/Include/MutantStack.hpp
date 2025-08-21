#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

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



template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		// Constructors
		MutantStack() {}
		MutantStack(const MutantStack &src)
		{
			*this = src;
		}

		// Destructor
		~MutantStack() {}

		// Operators overload
		MutantStack &operator=( const MutantStack &src )
		{
			this->c = src.c;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}

		const_iterator	begin() const
		{
			return (this->c.begin());
		}
		const_iterator	end() const
		{
			return (this->c.end());
		}

		reverse_iterator	rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator	rend()
		{
			return (this->c.rend());
		}

		const_reverse_iterator	rbegin() const
		{
			return (this->c.rbegin());
		}
		const_reverse_iterator	rend() const
		{
			return (this->c.rend());
		}
};

#endif