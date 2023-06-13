#include "easyfind.hpp"

int main(void)
{
    try
    {
        std::vector<int> x;
        for (int i = 0; i < 5; i++)
            x.push_back(i);
        std::vector<int>::iterator tmp = easyfind(x, 10);
        std::cout << "the element's index: " << *tmp << std::endl;
        return (0);
    }
    catch (ElementNotFound &e)
    {
        std::cout << RED << e.what() << DEFAULT << std::endl;
        return (1);
    }
}