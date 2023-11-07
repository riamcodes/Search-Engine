#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSAvlTree.h"

// TEST_CASE("contains", "[DSAvlTree]")
// {
//     DSAvlTree<std::string, int> test1;
//     test1.insert("HELLOO!", 1);
//     test1.insert("hi", 2);
//     REQUIRE(test1.contains("hi") == 2);
//     REQUIRE(test1.contains("HELLOO!")== 1);

//     DSAvlTree<char, int> test2;
//     test2.insert('c', 3);
//     test2.insert('!', 1);
//     REQUIRE(test2.contains('!') == 1);
//     REQUIRE(test2.contains('c') == 3);
// }

TEST_CASE("isEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    REQUIRE(test1.isEmpty() == true);
    test1.insert("HELLOO!", 5);
    test1.insert("hi", 1);
    REQUIRE(test1.isEmpty() == false);

    DSAvlTree<char, int> test2;
    REQUIRE(test2.isEmpty() == true);
    test2.insert('=', 0);
    test2.insert('!', 1);
    REQUIRE(test1.isEmpty() == false);
}

TEST_CASE("makeEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    test1.insert("HELLOOO", 3);
    test1.insert("hi", 0);
    test1.insert("HOLA", 4);
    test1.insert("heyyyy", 9000);
    test1.insert("hello", 1000000);
    test1.insert("idk", 1);
    test1.insert("HELLOOO", 100);
    test1.makeEmpty();
    REQUIRE(test1.isEmpty() == true);

    DSAvlTree<char, int> test2;
    test2.insert('c', 0);
    test2.insert('=', 100000000);
    test2.insert('!', 1000000);
    test2.insert('-', 8402489);
    test2.insert('@', 1);
    test2.makeEmpty();
    REQUIRE(test2.isEmpty() == true);
}

// TEST_CASE("public insert", "[DSAvlTree]")
// {
//     DSAvlTree<std::string> test1;
//     test1.insert("HELLOOOO");
//     REQUIRE(test1.contains("HELLOOOO") == true);
//     test1.insert("hiiiiiiiiiiiiii");
//     REQUIRE(test1.contains("hiiiiiiiiiiiiii") == true);

//     DSAvlTree<int> test2;
//     test2.insert(-1000000000);
//     REQUIRE(test2.contains(-1000000000) == true);
//     test2.insert(0);
//     REQUIRE(test2.contains(0) == true);

//     DSAvlTree<char> test3;
//     test3.insert('a');
//     REQUIRE(test3.contains('a') == true);
//     test3.insert('!');
//     REQUIRE(test3.contains('!') == true);
// }

// TEST_CASE("public remove", "[DSAvlTree]")
// {
//     SECTION("Testing case where previous == temp is true"){
//         DSAvlTree<int, int> test2;
//         test2.insert(6, 900);
//         test2.insert(4, 4);
//         test2.insert(7, 0);
//         test2.insert(2, 2233);
//         test2.insert(5, 1000000);
//         test2.remove(4);
//          REQUIRE(test2.contains(4) == false);
//     }

//     SECTION("Testing case where previous == temp is false"){
//         DSAvlTree<std::string, int> test1;
// test1.insert("HELLOOO", 3);
// test1.insert("hi", 0);
// test1.insert("HOLA", 4);
// test1.insert("heyyyy", 9000);
// test1.insert("hello", 1000000);
// test1.insert("idk", 1);
// test1.insert("HELLOOO", 100);
// test1.remove("hello");
// REQUIRE(test1.contains("hello") == false);

//        
//     }

//     SECTION("Testing case where previous == temp is false"){
//         DSAvlTree<int> test1;
//         test1.insert(6);
//         test1.insert(4);
//         test1.insert(7);
//         test1.insert(2);

//         test1.remove(4);
//     }
//      SECTION("Testing case where previous == temp is false"){
//         DSAvlTree<int> test1;
//         test1.insert(10);
//         test1.insert(6);
//         test1.insert(15);
//         test1.insert(2);
//         test1.insert(18);

//         test1.remove(6);
//     }