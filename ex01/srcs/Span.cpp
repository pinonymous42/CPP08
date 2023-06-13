#include "Span.hpp"

Span::Span(): _N(0)
{

}

Span::~Span()
{
    _vec.clear();
}

Span::Span(const Span &span)
{
    this->_N = span.getN();
    std::vector<int> tmp_vec = span.getVec();
    for (std::vector<int>::iterator i = tmp_vec.begin(); i != tmp_vec.end(); i++)
        this->_vec.push_back(*i);
}

Span &Span::operator=(const Span &span)
{
    if (this != &span)
    {
        if (this->_N != span.getN())
        {
            this->_vec.clear();
        }
        this->_N = span.getN();
        std::vector<int> tmp_vec = span.getVec();
        for (std::vector<int>::iterator i = tmp_vec.begin(); i != tmp_vec.end(); i++)
            this->_vec.push_back(*i);
    }
    return (*this);
}

void Span::addNumber(int num)
{
    if (this->_vec.size() == this->_N)
        throw AlreadyFull();
    this->_vec.push_back(num);
}

int Span::shortestSpan()
{
    if (this->_vec.size() == 0 || this->_vec.size() == 1)
        throw NoSpan();
    int min = std::abs(this->_vec[1] - this->_vec[0]);
    for (std::vector<int>::iterator tmp = this->_vec.begin() + 1; tmp != this->_vec.end() - 1; tmp++)
    {
        if (min > std::abs(*(tmp + 1) - *tmp))
            min = std::abs(*(tmp + 1) - *tmp);
    }
    return (min);
}

int Span::longestSpan()
{
    if (this->_vec.size() == 0 || this->_vec.size() == 1)
        throw NoSpan();
    int max = std::abs(this->_vec[1] - this->_vec[0]);
    for (std::vector<int>::iterator tmp = this->_vec.begin() + 1; tmp != this->_vec.end() - 1; tmp++)
    {
        if (max < std::abs(*(tmp + 1) - *tmp))
            max = std::abs(*(tmp + 1) - *tmp);
    }
    return (max);
}

Span::Span(unsigned int N)
{
    this->_N = N;
}

unsigned int Span::getN() const
{
    return (this->_N);
}

std::vector<int> Span::getVec() const
{
    return (this->_vec);
}