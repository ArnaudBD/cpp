#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <cstddef>
# include <iostream>

template < typename T >
class Array
{
private:
    T   *_array;
    unsigned int _size;
public:
    Array() : _array(NULL), _size(0) {}
    ~Array() { delete[] _array; }

    Array(unsigned int n) : _array(new T[n]), _size(n) {}
    Array(Array const &rhs) : _array(NULL), _size(0)
    {
        *this = rhs;
    }
    Array & operator=(Array const & rhs) 
    {
        delete[] _array;
        _size = rhs._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = rhs._array[i];
        }
        return (*this);
    }
    class FalseIndex : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Index is not correct");
        };
    };

    T & operator[](unsigned int index)
    {
        if (index >= _size || 0 > _size)
        {
            throw FalseIndex();
        }
        return (_array[index]);
    }
    int size() const
    {
        return (this->_size);
    }
    
};

#endif