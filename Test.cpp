#include <string>
#include <vector>
#include "snowman.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

/*
under 8 digit snowman checks
*/
TEST_CASE("Unvalid digit num - under"){
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
}

/*
over 8 digit snowman checks
*/
TEST_CASE("Unvalid digit num - over"){
    CHECK_THROWS(snowman(111111111)); // 9 dig
    CHECK_THROWS(snowman(1111111111)); // 10 dig
}

/*
8 digit snowman tests, using over 4 value 9 in every position.
*/
TEST_CASE("Unvalid digit format - over 4"){
    CHECK_THROWS(snowman(91111111)); // 9 at digit 1
    CHECK_THROWS(snowman(19111111)); // 9 at digit 2
    CHECK_THROWS(snowman(11911111)); // 9 at digit 3
    CHECK_THROWS(snowman(11191111)); // 9 at digit 4
    CHECK_THROWS(snowman(11119111)); // 9 at digit 5
    CHECK_THROWS(snowman(11111911)); // 9 at digit 6
    CHECK_THROWS(snowman(11111191)); // 9 at digit 7
    CHECK_THROWS(snowman(11111119)); // 9 at digit 8
}

/*
8 digit snowman tests, using under 1 value 0 in every position.
*/
TEST_CASE("Unvalid digit format - under 1"){
    CHECK_THROWS(snowman(01111111)); // 0 at digit 1
    CHECK_THROWS(snowman(10111111)); // 0 at digit 2
    CHECK_THROWS(snowman(11011111)); // 0 at digit 3
    CHECK_THROWS(snowman(11101111)); // 0 at digit 4
    CHECK_THROWS(snowman(11110111)); // 0 at digit 5
    CHECK_THROWS(snowman(11111011)); // 0 at digit 6
    CHECK_THROWS(snowman(11111101)); // 0 at digit 7
    CHECK_THROWS(snowman(11111110)); // 0 at digit 8
}

/*
8 digit snowman tests, using all types of snowman body parts.
*/
TEST_CASE("valid snowman examples"){
    CHECK(snowman(11111111) == "       \n _===_ \n (.,.) \n<( : )>\n ( : ) ");
    CHECK(snowman(22222222) == "  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") ");
    CHECK(snowman(33333333) == "   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) ");
    CHECK(snowman(44444444) == "  ___  \n (_*_) \n (- -) \n (   ) \n (   ) ");
}

/*
8 digit snowman tests, using wrong types of snowman body parts.
*/
TEST_CASE("unvalid snowman examples"){
    CHECK(snowman(11111111) != "       \n _===_ \n (.,.) \n<( : )>\n (___) ");      //snowman(11111113)
    CHECK(snowman(22222222) != "  ___  \n ..... \n (O_O) \n/(> <)\\\n (\" \") ");   //snowman(23333332)
    CHECK(snowman(33333333) != "   _   \n  /_\\  \n (O_O) \n/(] [)\\\n (___) ");    //snowman(33333323)
    CHECK(snowman(44444444) != "       \n _===_ \n (- -) \n (   ) \n (   ) ");      //snowman(14444444)
}
