#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <vector>

template <typename T>
typename T::iterator    easyfind( T &haystack, int needle )
{
    typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
    if (it == haystack.end())
        throw std::exception();
    return (it);
}

#endif