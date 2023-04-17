#include "doctest.h"
#include "sources/Fraction.hpp"
#include "sources/Fraction.cpp"
#include <stdexcept>

//using namespace ariel;


TEST_CASE("C'TOR")
{
    CHECK_NOTHROW(Fraction(1,2));
    CHECK_THROWS(Fraction(1,0));
}
