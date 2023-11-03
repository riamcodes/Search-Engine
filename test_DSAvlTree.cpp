#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSAvlTree.h"

TEST_CASE("contains", "[DSAvlTree]")
{
    DSAvlTree<std::string> test1;
    test1.insert("HELLOO!");
    test1.insert("hi");
    REQUIRE(test1.contains("hi") == true);
    REQUIRE(test1.contains("HELLOO!") == true);

    DSAvlTree<int> test2;
    REQUIRE(test2.contains(0000000) == false);
    test2.insert(-100000);
    test2.insert(0);
    REQUIRE(test2.contains(-100000) == true);

    DSAvlTree<char> test3;
    test3.insert('a');
    test3.insert('=');
    REQUIRE(test3.contains('a') == true);
    REQUIRE(test3.contains('=') == true);
}

TEST_CASE("isEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string> test1;
    REQUIRE(test1.isEmpty() == true);
    test1.insert("HELLOO!");
    test1.insert("hi");
    REQUIRE(test1.isEmpty() == false);

    DSAvlTree<int> test2;
    REQUIRE(test2.isEmpty() == true);
    test2.insert(-100000);
    test2.insert(0);
    REQUIRE(test1.isEmpty() == false);

    DSAvlTree<char> test3;
    REQUIRE(test3.isEmpty() == true);
    test3.insert('a');
    test3.insert('=');
    REQUIRE(test3.isEmpty() == false);
 }

// TEST_CASE("makeEmpty", "[DSAvlTree]")
// {
//     DSAvlTree<std::string> test1;
//     test1.insert("HELLOOO");
//     test1.insert("hi");
//     test1.insert("HOLA");
//     test1.insert("heyyyy");
//     test1.insert("hello");
//     test1.insert("idk");
//     test1.remove("hi");
//     test1.insert("HELLOOO");
//     test1.makeEmpty();
//     REQUIRE(test1.isEmpty() == true);

//     DSAvlTree<int> test2;
//     test2.insert(0);
//     test2.insert(100000000);
//     test2.insert(-1000000);
//     test2.insert(8402489);
//     test2.insert(1);
//     test2.remove(0);
//     test2.insert(10090844);
//     test2.insert(-47920298);
//     test2.insert(244824082);
//     test2.insert(-244808420);
//     test2.makeEmpty();
//     REQUIRE(test2.isEmpty() == true);

//     DSAvlTree<char> test3;
//     test3.insert('a');
//     test3.insert('!');
//     test3.insert('=');
//     test3.insert('_');
//     test3.insert('?');
//     test3.insert('*');
//     test3.insert('&');
//     test3.insert('b');
//     test3.remove('a');
//     test3.makeEmpty();
//     REQUIRE(test3.isEmpty() == true);
// }

TEST_CASE("public insert", "[DSAvlTree]")
{
    DSAvlTree<std::string> test1;
    test1.insert("HELLOOOO");
    REQUIRE(test1.contains("HELLOOOO") == true);
    test1.insert("hiiiiiiiiiiiiii");
    REQUIRE(test1.contains("hiiiiiiiiiiiiii") == true);

    DSAvlTree<int> test2;
    test2.insert(-1000000000);
    REQUIRE(test2.contains(-1000000000) == true);
    test2.insert(0);
    REQUIRE(test2.contains(0) == true);

    DSAvlTree<char> test3;
    test3.insert('a');
    REQUIRE(test3.contains('a') == true);
    test3.insert('!');
    REQUIRE(test3.contains('!') == true);
}

TEST_CASE("public remove", "[DSAvlTree]")
{
    SECTION("Testing case where previous == temp is true"){
        DSAvlTree<int> test1;
        test1.insert(6);
        test1.insert(4);
        test1.insert(7);
        test1.insert(2);
        test1.insert(5);

        test1.remove(4);
    }
    
    SECTION("Testing case where previous == temp is false"){
        DSAvlTree<int> test1;
        test1.insert(10);
        test1.insert(5);
        test1.insert(15);
        test1.insert(2);
        test1.insert(7);
        test1.insert(12);
        test1.insert(18);
        test1.insert(6);

        test1.remove(5);
    }

    SECTION("Testing case where previous == temp is false"){
        DSAvlTree<int> test1;
        test1.insert(6);
        test1.insert(4);
        test1.insert(7);
        test1.insert(2);

        test1.remove(4);
    }
     SECTION("Testing case where previous == temp is false"){
        DSAvlTree<int> test1;
        test1.insert(10);
        test1.insert(6);
        test1.insert(15);
        test1.insert(2);
        test1.insert(18);

        test1.remove(6);
    }
}