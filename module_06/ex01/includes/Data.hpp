#ifndef DATA_HPP
# define DATA_HPP
# include <string>
#include <stdint.h>

class Data
{
private:
    Data();
    Data( Data const & );
    Data & operator=( Data const & );
    std::string _var;
public:
    Data( std::string );
    ~Data();
    uintptr_t seralize( Data* );
    Data* deserialize( uintptr_t );
};

#endif