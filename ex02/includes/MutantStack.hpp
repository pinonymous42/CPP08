#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <iostream>
#include <deque>
#include <stack>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack()
        {

        }
        ~MutantStack()
        {

        }
        MutantStack(const MutantStack &mutantstack): std::stack<T, Container>(mutantstack)
        {

        }
        MutantStack &operator=(const MutantStack &mutantstack)
        {
            if (this != &mutantstack)
                std::stack<T, Container>::operator=(mutantstack);
            return (*this);
        }
        iterator begin()
        {
            return (this->std::stack<T, Container>::c.begin());
        }
        iterator end()
        {
            return (this->std::stack<T, Container>::c.end());
        }
        reverse_iterator rbegin()
        {
            return (this->std::stack<T, Container>::c.rbegin());
        }
        reverse_iterator rend()
        {
            return (this->std::stack<T, Container>::c.rend());
        }
        const_iterator begin() const
        {
            return (this->std::stack<T, Container>::c.begin());
        }
        const_iterator end() const
        {
            return (this->std::stack<T, Container>::c.end());
        }
        const_reverse_iterator rbegin() const
        {
            return (this->std::stack<T, Container>::c.rbegin());
        }
        const_reverse_iterator rend() const
        {
            return (this->std::stack<T, Container>::c.rend());
        }
    private:
};
#endif