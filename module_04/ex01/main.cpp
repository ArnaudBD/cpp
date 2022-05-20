#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete i;
delete j;
delete meta;

std::cout << "--------------------" << std::endl;

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* wd = new WrongDog();
const WrongAnimal* wc = new WrongCat();
std::cout << wd->getType() << " " << std::endl;
std::cout << wc->getType() << " " << std::endl;
wc->makeSound(); //will not output the cat sound!
wd->makeSound();
meta2->makeSound();
delete wd;
delete wc;
delete meta2;

return 0;
}