#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSAvlTree.h"

TEST_CASE("contains", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    test1.insert("HELLOO!", 1);
    test1.insert("hi", 2);
    std::vector<int> results = test1.contains("hi");
    REQUIRE(results.size() == 1);
    REQUIRE(results[0] == 2);
    results = test1.contains("HELLOO!");
    REQUIRE(results.size() == 1);
    REQUIRE(results[0] == 1);

    DSAvlTree<char, int> test2;
    test2.insert('c', 3);
    test2.insert('c', 1);
    std::vector<int> results2 = test2.contains('c');
    REQUIRE(results2.size() == 2);
    REQUIRE(results2[0] == 3);
    REQUIRE(results2[1] == 1);
}

TEST_CASE("isEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    REQUIRE(test1.isEmpty() == true);
    test1.insert("HELLOO!", 5);
    test1.insert("hi", 1);
    REQUIRE(test1.isEmpty() == false);
    test1.remove("HELLOO!");
    test1.remove("hi");
    REQUIRE(test1.isEmpty() == true);

    DSAvlTree<char, int> test2;
    REQUIRE(test2.isEmpty() == true);
    test2.insert('=', 0);
    test2.insert('!', 1);
    REQUIRE(test2.isEmpty() == false);
    test2.remove('=');
    test2.remove('!');
    REQUIRE(test2.isEmpty() == true);
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

TEST_CASE("public insert", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    test1.insert("HELLOOOO", 777777);
    std::vector<int> results3 = test1.contains("HELLOOOO");
    REQUIRE(results3.size() == 1);
    REQUIRE(results3[0] == 777777);
    test1.insert("hiiiiiiiiiiiiii", 0);
    results3 = test1.contains("hiiiiiiiiiiiiii");
    REQUIRE(results3.size() == 1);
    REQUIRE(results3[1] == 0);

    DSAvlTree<char, int> test2;
    test2.insert('!', 10000000);
    std::vector<int> results4 = test2.contains('!');
    REQUIRE(results4.size() == 1);
    REQUIRE(results4[0] == 10000000);
    test2.insert('A', 0);
    results4 = test2.contains('A');
    REQUIRE(results4.size() == 1);
    REQUIRE(results4[0] == 0);
}

TEST_CASE("public remove", "[DSAvlTree]")
{
    SECTION("Testing case where previous == temp is true")
    {
        DSAvlTree<int, int> test2;
        test2.insert(6, 900);
        std::vector<int> results = test2.contains(6);
        test2.insert(4, 4);
        results = test2.contains(4);
        test2.insert(7, 0);
        results = test2.contains(7);
        test2.insert(2, 2233);
        results = test2.contains(2);
        test2.insert(5, 1000000);
        results = test2.contains(5);
        REQUIRE(results.size() == 1);
        test2.remove(4);
        results.pop_back();
        REQUIRE(results.size() == 0);
    }

    SECTION("Testing case where previous == temp is false")
    {
        DSAvlTree<std::string, int> test1;
        std::vector<int> results2;
        test1.insert("HELLOOO", 3);
        results2 = test1.contains("HELLOOO");
        test1.insert("hi", 0);
        results2 = test1.contains("hi");
        test1.insert("HOLA", 4);
        results2 = test1.contains("HOLA");
        test1.insert("heyyyy", 9000);
        results2 = test1.contains("heyyyy");
        test1.insert("hello", 1000000);
        results2 = test1.contains("hello");
        test1.insert("idk", 1);
        results2 = test1.contains("idk");
        REQUIRE(results2.size() == 1);
        test1.remove("hello");
        results2.pop_back();
        REQUIRE(results2.size() == 0);
    }
}