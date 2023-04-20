#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;
using std::cout;
using std::endl;


TEST_CASE("C'TOR")
{
    CHECK_NOTHROW(Fraction(1,2));
    CHECK_THROWS(Fraction(1,0));
}


TEST_CASE("Telescoping series")
{
    int n = 100;
    Fraction seriesSum1(1,2);
    Fraction seriesSum2(1,2);

    /* 1/(1*2) + 1/(2*3) + ... + 1/n*(n+1) = n/n+1 */ 
    for(int i = 2; i <= n; i++)
    {
        seriesSum1 = seriesSum1 + Fraction(1, i*(i+1));
    }
    CHECK_EQ(seriesSum1 == Fraction(n, n+1), true);

    
    /* 1/2 + 2/3 + 3/4 + 4/5 ... + n/n+1 = 1/n+1 */
    for(int i = 2; i <= n; i++)
    {
        seriesSum2 = seriesSum2 * Fraction(i, i+1);
    }
    CHECK_EQ(seriesSum2 == Fraction(1, n+1), true);
}


TEST_CASE("Dividing by zero")
{
    CHECK_THROWS(Fraction(1,1)/Fraction(0,1));
    CHECK_THROWS(Fraction(1,1)/0);
    CHECK_THROWS(1/Fraction(0,1));
}


TEST_CASE("Subtract")
{
    Fraction a(1000, 100);
    Fraction b(100,10);
    Fraction c(10, 1);
    Fraction d(0,1);

    CHECK(a-b == 0);
    CHECK(b-c == d);
    CHECK(a-0 == a);
    CHECK(a-d == a);
    CHECK(10-a == 0);
}


TEST_CASE("Equalities & Inequalities")
{
    Fraction a(1,2);

    CHECK(a <= 0.5);
    CHECK(a >= 0.5);
    
    a++;
    CHECK(a == 1.5);
    
    CHECK_EQ(1 < a && a < 2, true);
    CHECK_EQ(2 > a && a > 1, true);

    a--;
    --a;
    CHECK(a*a*a == Fraction(-100, 800));
}


TEST_CASE("Order of Operations")
{
    Fraction a(1,1);
    Fraction b(2,1);
    Fraction c(3,1);

    CHECK(a+b*c == 7);
    CHECK((a+b)*c == 9);
}

