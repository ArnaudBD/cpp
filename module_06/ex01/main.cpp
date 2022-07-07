#include "Data.hpp"
#include <iostream>

int main()
{
    Data truc( "Hellow there!" );

    Data *trucPtr = &truc;
    std::cout << "Original pointer is: " << trucPtr << std::endl;
    uintptr_t machin = truc.serialize( trucPtr );
    std::cout << "Serialized pointer is: " << machin << std:: endl;
    Data *newPtr = truc.deserialize( machin );
    std::cout << "New pointer is: " << newPtr << std::endl;
    return 0;
}