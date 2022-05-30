#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	virtual ~Brain();
	Brain( Brain const & );
	Brain & operator=( Brain const & );

	void setIdea( int, std::string );
	std::string & getIdea( int );
};

#endif