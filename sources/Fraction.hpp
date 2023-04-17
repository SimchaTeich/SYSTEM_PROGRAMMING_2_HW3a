#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

using std::ostream;


namespace ariel
{
    class Fraction
    {
    private:
        int _numerator;
        int _denominator;


        /*
        Reduce the fraction.
        For example: Fraction(2,4) after
        reduce will hold 1 in _numerator
        and 2 in _denominator.
        */
        void recude();


        /*
        Create a reduced Fraction according to a double.
        (up to 3 digits beyond the desimal point for acuracy)
        For example: 12.34 --> Fraction(1234/100) --> Fraction(617/50)
                     0.567 --> Fractiob(567/1000) --> Fraction(567/1000)
        input: double
        output: reduced Fraction
        */
        static Fraction fractionFromDouble(double value);

    public:
        /*
        C'tor
        input: the integers for numerator and denominator.
        */
        Fraction(const int numerator, const int denominator);


        // getters
        int numerator() const;
        int denominator() const;


        /*
        overloading operator+
        note: the new Fraction will return will be in reduced form.
        */
        friend Fraction operator+(const Fraction& f1, const Fraction& f2);
        friend Fraction operator+(const Fraction& f, const double& value);
        friend Fraction operator+(const double& value, const Fraction& f);


        /*
        overloading operator-
        note: the new Fraction will return will be in reduced form.
        */
        friend Fraction operator-(const Fraction& f1, const Fraction& f2);
        friend Fraction operator-(const Fraction& f, const double& value);
        friend Fraction operator-(const double& value, const Fraction& f);


        /*
        overloading operator*
        note: the new Fraction will return will be in reduced form.
        */
        friend Fraction operator*(const Fraction& f1, const Fraction& f2);
        friend Fraction operator*(const Fraction& f, const double& value);
        friend Fraction operator*(const double& value, const Fraction& f);


        /*
        overloading operator/
        note: the new Fraction will return will be in reduced form.
        */
        friend Fraction operator/(const Fraction& f1, const Fraction& f2);
        friend Fraction operator/(const Fraction& f, const double& value);
        friend Fraction operator/(const double& value, const Fraction& f);


       /*
        overloading operator==
        note: fraction 1/2 and fraction 2/4 are equals.
        */
        friend bool operator==(const Fraction& f1, const Fraction& f2);
        friend bool operator==(const Fraction& f, const double& value);
        friend bool operator==(const double& value, const Fraction& f);
        
        
        /*
        overloading operator<
        */
        friend bool operator<(const Fraction& f1, const Fraction& f2);
        friend bool operator<(const Fraction& f, const double& value);
        friend bool operator<(const double& value, const Fraction& f);


        /*
        overloading operator>
        */
        friend bool operator>(const Fraction& f1, const Fraction& f2);
        friend bool operator>(const Fraction& f, const double& value);
        friend bool operator>(const double& value, const Fraction& f);
        
        
        // bool operator<=(const Fraction& other) const;
        // bool operator>=(const Fraction& other) const;


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