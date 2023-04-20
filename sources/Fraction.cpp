//https://www.learncpp.com/cpp-tutorial/overloading-the-arithmetic-operators-using-friend-functions/
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
    int denominator = 1000;
    value *= 1000;

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


Fraction ariel::operator+(const double& value, const Fraction& f)
{
    return  f + value;
}


Fraction ariel::operator-(const Fraction& f1, const Fraction& f2)
{
    int newNumorator = f1._numerator * f2._denominator - f2._numerator * f1._denominator;
    int newDenominator = f1._denominator * f2._denominator;
    
    // create the reduced form
    Fraction newFraction(newNumorator, newDenominator);
    newFraction.recude();

    return newFraction;
}


Fraction ariel::operator-(const Fraction& f, const double& value)
{
    return f - Fraction::fractionFromDouble(value);
}


Fraction ariel::operator-(const double& value, const Fraction& f)
{
    return  Fraction::fractionFromDouble(value) - f;
}


Fraction ariel::operator*(const Fraction& f1, const Fraction& f2)
{
    int newNumorator = f1._numerator * f2._numerator;
    int newDenominator = f1._denominator * f2._denominator;
    
    // create the reduced form
    Fraction newFraction(newNumorator, newDenominator);
    newFraction.recude();

    return newFraction;
}


Fraction ariel::operator*(const Fraction& f, const double& value)
{
    return f * Fraction::fractionFromDouble(value);
}


Fraction ariel::operator*(const double& value, const Fraction& f)
{
    return  f * value;
}


Fraction ariel::operator/(const Fraction& f1, const Fraction& f2)
{   
    return f1 * Fraction(f2._denominator, f2._numerator);
}


Fraction ariel::operator/(const Fraction& f, const double& value)
{
    return f / Fraction::fractionFromDouble(value);
}


Fraction ariel::operator/(const double& value, const Fraction& f)
{
    return  Fraction::fractionFromDouble(value) / f;
}


bool ariel::operator==(const Fraction& f1, const Fraction& f2)
{
    Fraction reducedLeft(f1._numerator, f1._denominator);
    reducedLeft.recude();

    Fraction reducedRight(f2._numerator, f2._denominator);
    reducedRight.recude();

    return reducedLeft._numerator == reducedRight._numerator && 
        reducedLeft._denominator == reducedRight._denominator;
}


bool ariel::operator==(const Fraction& f, const double& value)
{
    return f == Fraction::fractionFromDouble(value);
}


bool ariel::operator==(const double& value, const Fraction& f)
{
    return f == value;
}


bool ariel::operator<(const Fraction& f1, const Fraction& f2)
{
     return f1._numerator * f2._denominator < f1._denominator * f2._numerator;
}


bool ariel::operator<(const Fraction& f, const double& value)
{
     return f < Fraction::fractionFromDouble(value);
}


bool ariel::operator<(const double& value, const Fraction& f)
{
     return Fraction::fractionFromDouble(value) < f;
}


bool ariel::operator>(const Fraction& f1, const Fraction& f2)
{
     return f1._numerator * f2._denominator > f1._denominator * f2._numerator;
}


bool ariel::operator>(const Fraction& f, const double& value)
{
     return f > Fraction::fractionFromDouble(value);
}


bool ariel::operator>(const double& value, const Fraction& f)
{
     return Fraction::fractionFromDouble(value) > f;
}


bool ariel::operator<=(const Fraction& f1, const Fraction& f2)
{
    return f1 < f2 || f1 == f2;
}


bool ariel::operator<=(const Fraction& f, const double& value)
{
    return f <= Fraction::fractionFromDouble(value);
}


bool ariel::operator<=(const double& value, const Fraction& f)
{
    return Fraction::fractionFromDouble(value) <= f;
}


bool ariel::operator>=(const Fraction& f1, const Fraction& f2)
{
    return f1 > f2 || f1 == f2;
}


bool ariel::operator>=(const Fraction& f, const double& value)
{
    return f >= Fraction::fractionFromDouble(value);
}


bool ariel::operator>=(const double& value, const Fraction& f)
{
    return Fraction::fractionFromDouble(value) >= f;
}


Fraction& ariel::operator++(Fraction& f)
{
    f._numerator += f._denominator;
    return f;
}


Fraction& ariel::operator++(Fraction& f, int)
{
    f._numerator += f._denominator;
    return f;
}


ostream& ariel::operator<<(ostream& s, const Fraction& fraction)
{
    return s << fraction._numerator << "/" << fraction._denominator;
}
