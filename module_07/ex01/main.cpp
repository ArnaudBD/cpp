#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>

template <typename T>
void    fun( const T &value )
{
    // value = 'A';
    std::cout << "fun" << &value << std::endl;
}

int main(void)
{
    char    tab[5] = {'1', '2', '3', '4', 0};

    for (int i = 0; i < 5; i++)
    {
        std::cout << "tab[" << i << "]" << tab[i] << std::endl;
    }
    std::cout << "iter" << std::endl;
    ::iter(tab, 5, &fun);

    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << "tab[" << i << "]" << tab[i] << std::endl;
    // }
    
}
