#include <iostream>
#include "easyfind.hpp"

int main()
{
    int t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int needle = 5;
    std::vector<int> v(&t[0], &t[3]);
    
    try
    {
        easyfind(v, needle);
    }
    catch(const std::exception &)
    {
        std::cerr << needle << " not found" << std::endl;
    }
    for (int i = 3; i <= 9; i++)
        v.push_back(t[i]);
    try
    {
        easyfind(v, needle);
        std::cout << needle << " found!" << std::endl;
    }
    catch(const std::exception & )
    {
        std::cerr << needle << " not found" << std::endl;
    }
    
}