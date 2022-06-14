#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>
#include <typeinfo>

Base * generate( void )
{
    std::srand( time(NULL) );

    int r = rand() % 3;

    switch (r)
    {
    case 0:
        std::cout << "Randomly generated class: A" << std::endl;
        return (new A);
    case 1:
        std::cout << "Randomly generated class: B" << std::endl;
        return (new B);
    case 2:
        std::cout << "Randomly generated class: C" << std::endl;
        return (new C);
    }
    return NULL;
}

void identify( Base* p )
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Base pointer identified as A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Base pointer identified as B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Base pointer identified as C" << std::endl;
    else 
        std::cout << "Couldn't identify any class..." << std::endl;
}

void identify( Base& p )
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "Base reference identified as A" << std::endl;
    }
    catch( std::bad_cast &bc) {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "Base reference identified as B" << std::endl;
    }
    catch( std::bad_cast &bc) {}
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "Base reference identified as C" << std::endl;
    }
    catch( std::bad_cast &bc) {}
}

int main()
{
    Base *b;
    
    b = generate();
    identify(b);
    identify(*b);
    return 0;
}