#ifndef WHATEVER_HPP
# define WHATEVER_HPP


#endif
template < typename T >
void swap( T & x, T & y )
{
    T temp = x;
    x = y;
    y = temp;
    return ;
}

template < typename T >
T min( T & x, T & y )
{
    return ( x < y ? x : y );
}

template < typename T >
T max( T & x, T & y )
{
    return ( x > y ? x : y );
}