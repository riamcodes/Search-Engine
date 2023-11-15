#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSAvlTree.h"

TEST_CASE("contains", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi",1);
    test1.insert("HI", "hi",1);
    test1.insert("hola", "hi",1);
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 1);
    std::map<std::string, int>::iterator it = results.find("hola");
    REQUIRE(it == results.end());
    it = results.find("hi");
    REQUIRE(it != results.end());
    REQUIRE(results["hi"] == 100);

    DSAvlTree<int, int> test2;
    test2.insert(4, 200, 1);
    test2.insert(50, 200, 1);
    test2.insert(600, 200, 1);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 1);
    std::map<int, int>::iterator it1 = results2.find(4);
    REQUIRE(it1 == results2.end());
    it1 = results2.find(4);
    REQUIRE(it1 != results2.end());
    REQUIRE(results2[200] == 1);
}

TEST_CASE("isEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    REQUIRE(test1.isEmpty() == true);
    test1.insert("HELLO!", 4, 40);
    test1.insert("HI", 4, 200);
    test1.insert("hola", 4, 1);
    REQUIRE(test1.isEmpty() == false);

    DSAvlTree<char, std::string> test2;
    REQUIRE(test2.isEmpty() == true);
    test2.insert('!', "HI!", 200);
    test2.insert('H', "HI!", 20);
    test2.insert('I', "HI!", 500);
    REQUIRE(test2.isEmpty() == false);
}

TEST_CASE("makeEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    test1.insert("HELLO!", 5, 10);
    test1.insert("HI", 5, 200);
    test1.insert("hola", 5, 5);
    test1.insert("haha", 6, 100);
    test1.insert("lol", 6, 3);
    test1.makeEmpty();
    REQUIRE(test1.isEmpty() == true);

    DSAvlTree<char, int> test2;
    test2.insert('c', 0, 50);
    test2.insert('=', 100000000, 100);
    test2.insert('!', 1000000, 40);
    test2.insert('-', 8402489, 1);
    test2.insert('@', 1, 9);
    test2.makeEmpty();
    REQUIRE(test2.isEmpty() == true);
}

TEST_CASE("insert", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi", 70);
    test1.insert("HI", "hi", 1);
    test1.insert("hola", "hi", 100);
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 1);
    std::map<std::string, int>::iterator it = results.find("hola");
    REQUIRE(it == results.end());
    it = results.find("hi");
    REQUIRE(it != results.end());
    REQUIRE(results["hi"] == 100);

    DSAvlTree<int, int> test2;
    test2.insert(4, 200, 10);
    test2.insert(50, 200, 5);
    test2.insert(600, 200, 7);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 1);
    std::map<int, int>::iterator it1 = results2.find(4);
    REQUIRE(it1 == results2.end());
    it1 = results2.find(4);
    REQUIRE(it1 != results2.end());
    REQUIRE(results2[200] == 1);

}

TEST_CASE("remove", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi", 70);
    test1.insert("HI", "hi", 1);
    test1.insert("hola", "hi", 100);
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 1);
    std::map<std::string, int>::iterator it = results.find("hola");
    REQUIRE(it == results.end());
    it = results.find("hi");
    REQUIRE(it != results.end());
    REQUIRE(results["hi"] == 100);
    test1.remove("hola");
    results.erase("hola");

    DSAvlTree<int, int> test2;
    test2.insert(4, 200, 10);
    test2.insert(50, 200, 100);
    test2.insert(600, 200, 1);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 1);
    std::map<int, int>::iterator it1 = results2.find(4);
    REQUIRE(it1 == results2.end());
    it1 = results2.find(4);
    REQUIRE(it1 != results2.end());
    REQUIRE(results2[200] == 1);
    // test2.remove(4);
    // results2.erase(4);
}