#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class Span
{
    public:
    typedef std::vector<int>::iterator iterator;
        Span();
        ~Span();
        Span(const Span &span);
        Span &operator=(const Span &span);
        Span(unsigned int N);
        void addNumber(int num);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        unsigned int getN() const;
        std::vector<int> getVec() const;
        class AlreadyFull: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("The container is already full!");
                }
            private:
        };
        class NoSpan: public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("There is no span in the container!");
            }
            private:
        };
    private:
        unsigned int _N;
        std::vector<int> _vec;
};
#endif