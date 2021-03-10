#include <string>
#include <algorithm>
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;
using namespace std;
TEST_CASE("num of digits > 8")
{
    CHECK_THROWS(snowman(113424266));
    CHECK_THROWS(snowman(242223333));
    CHECK_THROWS(snowman(222222223));
    CHECK_THROWS(snowman(444444442));
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(123123123));
}
TEST_CASE("num of digits < 8")
{
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12344));
    CHECK_THROWS(snowman(123444));
    CHECK_THROWS(snowman(1234444));
}

TEST_CASE("num of digits < 8  but the value is negative")
{
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-12312313));
    CHECK_THROWS(snowman(-32132112));
    CHECK_THROWS(snowman(-43211234));
    CHECK_THROWS(snowman(-43214321));
    CHECK_THROWS(snowman(-33333333));
    CHECK_THROWS(snowman(-22211222));
}
TEST_CASE("not legal 8 digit num ")
{

    CHECK_THROWS(snowman(91111111));
    CHECK_THROWS(snowman(19111111));
    CHECK_THROWS(snowman(28224442));
    CHECK_THROWS(snowman(11712341));
    CHECK_THROWS(snowman(21262122));
    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(12422812));
    CHECK_THROWS(snowman(11111194));
    CHECK_THROWS(snowman(12431117));
}
TEST_CASE("Valid cases:")
{
    //Hat Cases
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(44241342) == string("  ___ \n (_*_)\n (o -) \n<(   )\\\n (\" \")"));
    CHECK(snowman(31421312) == string("   _  \n  /_\\ \n (-,o) \n<( : )\\\n (\" \")"));
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));

    //Nose cases
    CHECK(snowman(34332212) == string("   _  \n  /_\\ \n\\(O O)/\n ( : ) \n (\" \")"));
    CHECK(snowman(11111111) == string("      \n _===_\n (.,.) \n<( : )>\n ( : )"));
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/\n<( : ) \n (\" \")"));
    CHECK(snowman(43312222) == string("  ___ \n (_*_)\n\\(O_.)/\n (] [) \n (\" \")"));

    //Left Eye cases
    CHECK(snowman(44332211) == string("  ___ \n (_*_)\n\\(O O)/\n ( : ) \n ( : )"));
    CHECK(snowman(12341424) == string("      \n _===_\n (O.-) \n<(] [) \n (   )"));
    CHECK(snowman(14322341) == string("      \n _===_\n\\(O o) \n (   )\\\n ( : )"));
    CHECK(snowman(12311111) == string("      \n _===_\n (O..) \n<( : )>\n ( : )"));

    //Right Eye cases
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(42424222) == string("  ___ \n (_*_)\n (-.o)/\n (] [) \n (\" \")"));
    CHECK(snowman(11223344) == string("      \n _===_\n (o,o) \n/(   )\\\n (   )"));
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/\n<( : ) \n (\" \")"));
    //Left Arm cases
    CHECK(snowman(12341111) == string("      \n _===_\n (O.-) \n<( : )>\n ( : )"));
    CHECK(snowman(43242312) == string("  ___ \n (_*_)\n\\(o_-) \n ( : )\\\n (\" \")"));
    CHECK(snowman(33333333) == string("   _  \n  /_\\ \n (O_O) \n/(> <)\\\n (___)"));
    CHECK(snowman(11114111) == string("      \n _===_\n (.,.) \n ( : )>\n ( : )"));

    //Right Arm cases
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(42424222) == string("  ___ \n (_*_)\n (-.o)/\n (] [) \n (\" \")"));
    CHECK(snowman(43242312) == string("  ___ \n (_*_)\n\\(o_-) \n ( : )\\\n (\" \")"));
    CHECK(snowman(33333433) == string("   _  \n  /_\\ \n (O_O) \n/(> <) \n (___)"));

    //Toss cases
    CHECK(snowman(31421322) == string("   _  \n  /_\\ \n (-,o) \n<(] [)\\\n (\" \")"));
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(33333443) == string("   _  \n  /_\\ \n (O_O) \n/(   ) \n (___)"));

    //Base cases
    CHECK(snowman(11111111) == string("      \n _===_\n (.,.) \n<( : )>\n ( : )"));
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/\n<( : ) \n (\" \")"));
    CHECK(snowman(33333433) == string("   _  \n  /_\\ \n (O_O) \n/(> <) \n (___)"));
    CHECK(snowman(12341424) == string("      \n _===_\n (O.-) \n<(] [) \n (   )"));
}
