#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>

// template <typename T>
// void    fun( const T &value )
// {
//     // value = 'A';
//     std::cout << "fun" << &value << std::endl;
// }

// int main(void)
// {
//     char    tab[5] = {'1', '2', '3', '4', 0};

//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << "tab[" << i << "]" << tab[i] << std::endl;
//     }
//     std::cout << "iter" << std::endl;
//     ::iter(tab, 5, &fun);

//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << "tab[" << i << "]" << tab[i] << std::endl;
//     }
    
// }

class Awesome
{
    public:
        Awesome(void) : _n(42) {return;}
        int get(void) const {return this->_n;}
    private:
        int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) {o << rhs.get(); return o; }
template<typename T>
void print(T const & x ) { std::cout << x << std::endl; return; }

int main()
{
    int tab[] = {0, 1, 2, 3, 4 }; 
    Awesome tab2[5];

    iter( tab, 5, print );
    iter( tab2, 5, print );

    return 0;
}