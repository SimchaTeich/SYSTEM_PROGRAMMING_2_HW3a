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


Fraction Fraction::fractionFromDouble(double value)
{
    int denominator = 1;

    while(value - (int)value != 0)
    {
        denominator *= 10;
        value *= 10;
    }

    Fraction f(value, denominator);
    f.recude();
    return f;
}


int Fraction::numerator() const
{
    return _numerator;   
}


int Fraction::denominator() const
{
    return _denominator;
}


Fraction ariel::operator+(const Fraction& f1, const Fraction& f2)
{
    int newNumorator = f1._numerator * f2._denominator + f2._numerator * f1._denominator;
    int newDenominator = f1._denominator * f2._denominator;
    
    // create the reduced form
    Fraction newFraction(newNumorator, newDenominator);
    newFraction.recude();

    return newFraction;
}


Fraction ariel::operator+(const Fraction& f, const double& value)
{
    return f + Fraction::fractionFromDouble(value);
}


ostream& ariel::operator<<(ostream& s, const Fraction& fraction)
{
    return s << fraction._numerator << "/" << fraction._denominator;
}
