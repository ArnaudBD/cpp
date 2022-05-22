#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

// Animal a;

const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

std::cout << "- - - - -" << std::endl;

Dog deepCopy;
std::cout << "deepCopy idea is " << deepCopy.showThought( 0 ) << std::endl;
{
    Dog test = deepCopy;
    std::cout << "test idea is " << test.showThought( 0 ) << std::endl;
}

std::cout << "- - - - -" << std::endl;

Animal *NoasArk[10];

for (int i = 0 ; i < 5 ; i++)
{
    NoasArk[i] = new Dog();
    NoasArk[i]->makeSound();
}

for (int i = 5 ; i < 10 ; i++)
{
    NoasArk[i] = new Cat();
    NoasArk[i]->makeSound();
}

for (int i = 0 ; i < 10 ; i++)
{
    delete NoasArk[i];
}


// (void)NoasArk;
}
