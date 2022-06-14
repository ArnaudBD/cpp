#include "includes/Data.hpp"
#include <iostream>

Data::Data( std::string var ) : _var(var) 
{
}

Data::~Data()
{
}

uintptr_t serialize( Data* ptr )
{
    return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data* deserialize( uintptr_t raw )
{
    return ( reinterpret_cast<Data *>(raw) );
}

int main()
{
    Data truc( "Hellow there!" );

    Data *trucPtr = &truc;
    std::cout << "Original pointer is: " << trucPtr << std::endl;
    uintptr_t machin = serialize( trucPtr );
    std::cout << "Serialized pointer is: " << machin << std:: endl;
    Data *newPtr = deserialize( machin );
    std::cout << "New pointer is: " << newPtr << std::endl;
    return 0;
}