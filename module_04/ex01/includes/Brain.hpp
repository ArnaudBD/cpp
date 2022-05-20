#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain(/* args */);
	virtual ~Brain();
	Brain( Brain const & );
	Brain & operator=( Brain const & );
};

#endif