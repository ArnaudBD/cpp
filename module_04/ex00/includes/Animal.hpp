#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
private:
protected:
	std::string type;
public:
	Animal();
	~Animal();
	Animal( Animal const & );
	Animal & operator=( Animal const & );
};

#endif