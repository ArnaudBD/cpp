#ifndef DATA_HPP
# define DATA_HPP
# include <string>
# include <stdint.h>

class Data
{
private:
    Data();
    Data( Data const & );
    Data & operator=( Data const & );
public:
    Data( std::string );
    std::string _var;
    virtual ~Data();
    uintptr_t serialize( Data* );
    Data* deserialize( uintptr_t );
    void fake( void ) {};
};

#endif