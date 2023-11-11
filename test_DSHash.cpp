#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Hash.h"

TEST_CASE("clear", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0);
    test1.insert("hii", 1000);
    REQUIRE(test1.getSize() == 2);
    test1.clear();
    REQUIRE(test1.getSize() == 0);

    Hash<char, int> test2;
    test2.insert('!', 1);
    test2.insert('+', 1000000);
    test2.insert('@', 100);
    REQUIRE(test2.getSize() == 3);
    test2.clear();
    REQUIRE(test2.getSize() == 0);
}

TEST_CASE("clone", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0);
    test1.insert("hii", 1000);
    test1.insert("hola", 1);
    Hash<std::string, int> test2;
    test2.clone(test1);
    //REQUIRE(test1[0] == test2[0]);
    REQUIRE(test1.getSize() == test2.getSize());

    Hash<char, int> test3;
    test3.insert('!', 1);
    test3.insert('+', 1000000);
    test3.insert('@', 100);
    Hash<char, int> test4;
    test4.clone(test3);
    REQUIRE(test4.getSize() == test3.getSize());
}

TEST_CASE("insert", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0);
    test1.insert("hii", 1000);
    test1.insert("grace", 10);
    test1.insert("hii!!", 1000000);
    test1.insert("HELLO", 5500924);
    test1.insert("haha", 8);
    test1.insert("data", 90024);
    test1.insert("structures", 1);
    test1.insert("class", 789);
    test1.insert("lol", 10000);
    std::vector<int> result2 = test1.find("haha");
    REQUIRE(result2.size() == 1);

    Hash<char, int> test2;
    test2.insert('A', 0);
    test2.insert('=', 10);
    test2.insert('#', 9087);
    test2.insert('%', 6793);
    test2.insert('J', 234);
    test2.insert('*', 37840);
    std::vector<int> result = test2.find('A');
    REQUIRE(result.size() == 1);
}

TEST_CASE("get size", "[DSHash]")
{
    Hash<std::string, int> test1;
    test1.insert("HELLOOOOO", 0);
    test1.insert("hii", 1000);
    test1.insert("grace", 10);
    test1.insert("hii!!", 1000000);
    test1.insert("HELLO", 5500924);
    test1.insert("haha", 8);
    test1.insert("data", 90024);
    test1.insert("structures", 1);
    test1.insert("class", 789);
    test1.insert("lol", 10000);
    REQUIRE(test1.getSize() == 10);
    test1.clear();
    REQUIRE(test1.getSize() == 0);

    Hash<char, int> test2;
    test2.insert('!', 1);
    test2.insert('+', 1000000);
    test2.insert('@', 100);
    REQUIRE(test2.getSize() == 3);
    test2.insert('A', 0);
    test2.insert('=', 10);
    test2.insert('#', 9087);
    test2.insert('%', 6793);
    test2.insert('J', 234);
    test2.insert('*', 37840);
    REQUIRE(test2.getSize() == 9);
    test2.clear();
    REQUIRE(test2.getSize() == 0);
}

TEST_CASE("find", "[DSHash]")
{
    
}

TEST_CASE("rehash", "[DSHash]")
{
    
}