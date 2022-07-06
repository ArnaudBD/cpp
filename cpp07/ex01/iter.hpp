#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>
#include <iostream>

#endif
template < typename T >
void    iter( T *tab, int tabSize, void (*function)(const T &) )
{
    for (int i = 0; i < tabSize; i++)
    {
std::cout << i << std::endl;

        function(tab[i]);
    }
}