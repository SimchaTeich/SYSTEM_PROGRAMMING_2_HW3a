#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

using std::ostream;
using std::endl;


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

        /*
        Prints Fraction object into output stream.
        For example, [cout << Fraction(1,2)] will
        print: "1\2" into cout stream.
        input: stream and Fraction object.
        output: the stream after changes.
        */
        friend ostream& operator<<(ostream& s, const Fraction& fraction);
    };
};

#endif // !FRACTION_HPP