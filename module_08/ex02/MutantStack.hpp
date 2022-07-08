#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>
# include <iterator>

template< typename T, typename Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    typename MutantStack<T>::container_type::iterator begin()
    {
        return this->c.begin();
    }
    typename MutantStack<T>::container_type::iterator end()
    {
        return this->c.end();
    }
    typename MutantStack<T>::container_type::iterator begin() const
    {
        return this->c.begin();
    }
    typename MutantStack<T>::container_type::iterator end() const
    {
        return this->c.end();
    }

};
#endif