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

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* wd = new WrongDog();
const WrongAnimal* wc = new WrongCat();
std::cout << wd->getType() << " " << std::endl;
std::cout << wc->getType() << " " << std::endl;
wc->makeSound(); //will not output the cat sound!
wd->makeSound();
meta2->makeSound();

return 0;
}