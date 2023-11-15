#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Hash.h"

TEST_CASE("clear", "[DSHash]")
{
    Hash<std::string, std::string> test1;
    test1.insert("HELLO!", "hi",1);
    test1.insert("HI", "hi",1);
    test1.insert("hola", "hi",1);
    std::map<std::string, int> results = test1.find("hola");
    results = test1.find("HI");
    results = test1.find("HELLO!");
    REQUIRE(results.size() == 1);
    results.clear();
    test1.clear();
    REQUIRE(results.size() == 0);

    Hash<int, int> test2;
    test2.insert(4, 200, 1);
    test2.insert(50, 200, 1);
    test2.insert(600, 200, 1);
    std::map<int, int> results2 = test2.find(4);
    results2 = test2.find(50);
    results2 = test2.find(600);
    REQUIRE(results2.size() == 1);
    results2.clear();
    test1.clear();
    REQUIRE(results.size() == 0);
}

TEST_CASE("clone", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0, 8);
    test1.insert("hii", 1000, 7);
    test1.insert("hola", 1, 100);
    Hash<std::string, int> test2;
    test2.clone(test1);
    REQUIRE(test1.getSize() == test2.getSize());

    Hash<char, int> test3;
    test3.insert('!', 1, 80);
    test3.insert('+', 1000000, 2);
    test3.insert('@', 100, 20);
    Hash<char, int> test4;
    test4.clone(test3);
    REQUIRE(test4.getSize() == test3.getSize());
}

TEST_CASE("insert", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0, 8);
    test1.insert("hii", 1000, 9);
    test1.insert("grace", 10, 1);
    test1.insert("hii!!", 1000000, 78);
    test1.insert("HELLO", 5500924, 45);
    test1.insert("haha", 8, 7);
    test1.insert("data", 90024, 65);
    test1.insert("structures", 1, 9);
    test1.insert("class", 789, 1);
    test1.insert("lol", 10000, 2);
    REQUIRE(test1.getSize() == 10);

    Hash<char, int> test2;
    test2.insert('A', 0, 7);
    test2.insert('=', 10, 90);
    test2.insert('#', 9087, 1);
    test2.insert('%', 6793, 34);
    test2.insert('J', 234, 5);
    test2.insert('*', 37840, 20);
    REQUIRE(test2.getSize() == 6);
}

TEST_CASE("get size", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0, 1);
    test1.insert("hii", 1000, 20);
    test1.insert("grace", 10, 90);
    test1.insert("hii!!", 1000000, 1);
    test1.insert("HELLO", 5500924, 200);
    test1.insert("haha", 8, 8);
    test1.insert("data", 90024, 99);
    test1.insert("structures", 1, 4);
    test1.insert("class", 789, 56);
    test1.insert("lol", 10000, 78);
    REQUIRE(test1.getSize() == 10);
    test1.clear();
    REQUIRE(test1.getSize() == 0);

    Hash<char, int> test2;
    test2.insert('!', 1, 80);
    test2.insert('+', 1000000, 1);
    test2.insert('@', 100, 55);
    REQUIRE(test2.getSize() == 3);
    test2.insert('A', 0, 88);
    test2.insert('=', 10, 98);
    test2.insert('#', 9087, 5);
    test2.insert('%', 6793, 7);
    test2.insert('J', 234, 9);
    test2.insert('*', 37840, 8);
    REQUIRE(test2.getSize() == 9);
    test2.clear();
    REQUIRE(test2.getSize() == 0);
}