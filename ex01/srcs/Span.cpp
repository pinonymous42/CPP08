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

Span::Span(unsigned int N)
{
    this->_N = N;
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

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (this->_N - this->_vec.size() < static_cast<unsigned int>(end - start))
        throw AlreadyFull();
    this->_vec.insert(this->_vec.end(), start, end);
}

unsigned int Span::shortestSpan()
{
    if (this->_vec.size() <= 1)
        throw NoSpan();
    int min = Span::longestSpan();
    for (iterator i  = this->_vec.begin(); i != this->_vec.end(); i++)
    {
        for (iterator j = this->_vec.begin(); j != this->_vec.end(); j++)
        {
            if (*i == *j)
                continue;
            if (min > std::abs(*i - *j))
                min = std::abs(*i - *j);
        }
    }
    return (min);
}

unsigned int Span::longestSpan()
{
    if (this->_vec.size() <= 1)
        throw NoSpan();
    unsigned int max = *std::max_element(this->_vec.begin(), this->_vec.end())
        - *std::min_element(this->_vec.begin(), this->_vec.end());
    return (max);
}

unsigned int Span::getN() const
{
    return (this->_N);
}

std::vector<int> Span::getVec() const
{
    return (this->_vec);
}

std::vector<int>::iterator Span::begin()
{
    return (this->_vec.begin());
}

std::vector<int>::const_iterator Span::begin() const
{
    return (this->_vec.begin());
}

std::vector<int>::iterator Span::end()
{
    return (this->_vec.end());
}

std::vector<int>::const_iterator Span::end() const
{
    return (this->_vec.end());
}