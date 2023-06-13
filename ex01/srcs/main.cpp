#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);


        // Span sp1 = Span(10);
        // sp1.addNumber(100);
        // sp1.addNumber(sp.begin(), sp.end());
        
        // Span sp = Span(10000);
        // for (int i = 0; i < 10000; i++)
        //     sp.addNumber(i);

        // Span sp = Span(1);
        // sp.addNumber(1);

        // Span sp = Span(5);
        // sp.addNumber(1);
        // sp.addNumber(0);
        // sp.addNumber(INT_MAX);
        // sp.addNumber(INT_MIN);
        // for (std::vector<int>::iterator i = sp1.begin(); i != sp1.end(); i++)
        //     std::cout << *i << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }
    catch (Span::AlreadyFull &e)
    {
        std::cout << RED << e.what() << DEFAULT << std::endl;
        return (1);
    }
    catch (Span::NoSpan &e)
    {
        std::cout << RED << e.what() << DEFAULT << std::endl;
        return (1);
    }
}