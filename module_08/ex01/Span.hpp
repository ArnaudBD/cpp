#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <vector>

class Span
{
private:
    std::vector<int>    _v;
    size_t              _max;

    Span();
public:
    Span(unsigned int N);
    ~Span();
    Span( Span const & );
    Span & operator=( Span const & );

    void addNumber( int );
    size_t shortestSpan( void );
    size_t longestSpan( void );


};

#endif