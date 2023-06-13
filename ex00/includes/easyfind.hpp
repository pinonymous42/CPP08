#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define DEFAULT "\033[0m"

class ElementNotFound: public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("element not found !");
        }
    private:

};

template <typename T> typename T::iterator easyfind(T &containers, int to_find)
{
    typename T::iterator tmp = std::find(containers.begin(), containers.end(), to_find);
    if (tmp == containers.end())
        throw ElementNotFound();
    return (tmp);

}
#endif