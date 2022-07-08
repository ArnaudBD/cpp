#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(50000);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    for (int i = 0; i < 10000; i++)
    {
        std::srand( time(NULL) );
        int r = rand();
        sp.addNumber(r + i);
    }
    std::cout << "Shortest span: " <<sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;


    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    Span s2(10);
    s2.addRange(v.begin(), v.end());
    s2.display();
    std::cout << "Shortest span: " <<s2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << s2.longestSpan() << std::endl;
    return 0;
}