#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <cmath>

#define main program_main
#include "../lab_05.1.cpp"
#undef main

TEST_CASE("Перевірка функції k")
{
    // k(1, 0) = 1/(1+sin^2(0)) + 0/(1+1) = 1  (рахуємо вручну)
    CHECK(k(1, 0) == doctest::Approx(1.0));
}