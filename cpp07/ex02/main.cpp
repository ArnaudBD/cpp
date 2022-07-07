#include "Array.hpp"
#include <iostream>
#include <cstdlib>

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
        obj[-19] = 23;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//         else
//             std::cout << "Same value saved for i == " << i << std::endl;
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }