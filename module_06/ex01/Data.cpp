#include "Data.hpp"

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