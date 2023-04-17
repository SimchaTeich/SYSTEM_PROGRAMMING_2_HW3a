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
        /*
        C'tor
        input: the integers for numerator and denominator.
        */
        Fraction(const int numerator, const int denominator);
    };
};

#endif // !FRACTION_HPP