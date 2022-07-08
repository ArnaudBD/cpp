#include "Span.hpp"
#include <numeric>

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(unsigned int N) : _max(N)
{
}

Span::Span( Span const & copy )
{
    *this = copy;
    return ;
}

Span & Span::operator=( Span const & rhs )
{
    this->_max = rhs._max;
    this->_v = rhs._v;
    return (*this);
}

void Span::addNumber( int n )
{
    if (_v.size() < this->_max)
        this->_v.push_back(n);
    else
        throw std::exception();
}

size_t Span::shortestSpan( void )
{
    std::vector<int> v = this->_v;

    std::sort(v.begin(), v.end());
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    return (*std::min_element(v.begin(), v.end()));

}

size_t Span::longestSpan( void )
{
    std::vector<int> v = this->_v;

    std::sort(v.begin(), v.end());
    return (*(v.end() - 1) - *v.begin());

}
