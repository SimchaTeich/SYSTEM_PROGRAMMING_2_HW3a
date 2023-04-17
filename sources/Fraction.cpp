#include "Fraction.hpp"

using namespace ariel;
using std::endl;


Fraction::Fraction(const int numerator, const int denominator)
{
    _numerator = numerator;
    _denominator = denominator;
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
