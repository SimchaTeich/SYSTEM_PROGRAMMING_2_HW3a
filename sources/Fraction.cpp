#include "Fraction.hpp"

using namespace ariel;
using std::endl;


Fraction::Fraction(const int numerator, const int denominator)
{
    if(0 == denominator)
    {
        throw "ERROR: denominator can't be zero!";
    }

    _numerator = numerator;
    _denominator = denominator;
}


void Fraction::recude()
{
    int max = std::max(_numerator, _denominator);
    int quotient = 0;

    for(int i = 2; i <= max; i++)
    {
        while(_numerator % i == 0 && _denominator % i == 0)
        {
            _numerator /= i;
            _denominator /= i;
        }
    }
}


int Fraction::numerator() const
{
    return _numerator;
}


int Fraction::denominator() const
{
    return _denominator;
}


ostream& ariel::operator<<(ostream& s, const Fraction& fraction)
{
    return s << fraction._numerator << "/" << fraction._denominator;
}
