#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> obj(5);
    for (int i = 0; i < 5; i++)
    {
        obj[i] = i;
        std::cout << obj[i] << std::endl;
    }
    Array<int> copy = obj;
    copy[3] = 14;
    std::cout << "copy" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "obj[" << i << "] = " << obj[i] << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
    try
    {
        obj[19] = 23;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}