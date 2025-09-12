#include "../Include/Span.hpp"

// Constructors
Span::Span( unsigned int size )
{
	std::cout << "\tSpan default constructor called with size " << size << std::endl;
	this->_vec.reserve(size);
}

Span::Span( const Span &src )
{
	std::cout << "\tSpan copy constructor called" << std::endl;
	*this = src;
}



// Destructor
Span::~Span()
{
	std::cout << "\tSpan destructor called" << std::endl;
}



// Operators overload
Span	&Span::operator=( const Span &src )
{
	std::cout << "\tSpan assignation operator called" << std::endl;
	this->_vec.reserve(src._vec.capacity());
	this->_vec = src._vec;
	return (*this);
}



// Public class member functions
void	Span::addNumber( int n ) {
	if (this->_vec.size() == this->_vec.capacity())
		throw FullException();
	this->_vec.push_back(n);
	// std::cout << "\tNumber " << n << " added" << std::endl;
}

void	Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	if (std::distance(begin, end) > _vec.capacity() - _vec.size())
		throw FullException();
	this->_vec.insert(this->_vec.end(), begin, end);
}

void	Span::addVector( std::vector<int> v )
{
	if (std::distance(v.begin(), v.end()) > _vec.capacity() - _vec.size())
		throw FullException();
	this->_vec.insert(this->_vec.end(), v.begin(), v.end());
}

int	Span::shortestSpan() const
{
	if (this->_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (int i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int	Span::longestSpan() const
{
	if (this->_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
