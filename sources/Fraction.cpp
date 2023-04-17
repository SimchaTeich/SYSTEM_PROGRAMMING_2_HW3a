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


ostream& operator<<(ostream& s, const Fraction& fraction)
{
    s << fraction.numerator() << "/" << fraction.denominator() << endl;
}