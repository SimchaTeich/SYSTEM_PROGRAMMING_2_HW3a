#ifndef FRACTION_HPP
#define FRACTION_HPP

namespace ariel
{
    class Fraction
    {
    private:
        int _numerator;
        int _denominator;

    public:
        Fraction(const int numerator, const int denominator);
    };
};

#endif // !FRACTION_HPP