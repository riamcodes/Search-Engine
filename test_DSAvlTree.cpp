#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSAvlTree.h"

TEST_CASE("contains", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi");
    test1.insert("HI", "hi");
    test1.insert("hola", "hi");
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 3);
    std::map<std::string, int>::iterator it = results.find("hola");

    DSAvlTree<int, int> test2;
    test2.insert(4, 200);
    test2.insert(50, 200);
    test2.insert(600, 200);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 3);
    std::map<int, int>::iterator it1 = results2.find(4);
}

TEST_CASE("isEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    REQUIRE(test1.isEmpty() == true);
    test1.insert("HELLO!", 4);
    test1.insert("HI", 4);
    test1.insert("hola", 4);
    REQUIRE(test1.isEmpty() == false);

    DSAvlTree<char, std::string> test2;
    REQUIRE(test2.isEmpty() == true);
    test2.insert('!', "HI!");
    test2.insert('H', "HI!");
    test2.insert('I', "HI!");
    REQUIRE(test2.isEmpty() == false);
}

TEST_CASE("makeEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string, int> test1;
    test1.insert("HELLO!", 5);
    test1.insert("HI", 5);
    test1.insert("hola", 5);
    test1.insert("haha", 6);
    test1.insert("lol", 6);
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
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi");
    test1.insert("HI", "hi");
    test1.insert("hola", "hi");
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 3);
    std::map<std::string, int>::iterator it = results.find("hola");

    DSAvlTree<int, int> test2;
    test2.insert(4, 200);
    test2.insert(50, 200);
    test2.insert(600, 200);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 3);
    std::map<int, int>::iterator it1 = results2.find(4);

}

TEST_CASE("public remove", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi");
    test1.insert("HI", "hi");
    test1.insert("hola", "hi");
    std::map<std::string, int> results = test1.contains("hola");
    results = test1.contains("HI");
    results = test1.contains("HELLO!");
    REQUIRE(results.size() == 3);
    test1.remove("HI");
    results.erase("HI");
    REQUIRE(results.size() == 2);

    DSAvlTree<int, int> test2;
    test2.insert(4, 200);
    test2.insert(50, 200);
    test2.insert(600, 200);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 3);
    test2.remove(4);
    results2.erase(4);
    REQUIRE(results.size() == 2);
    // SECTION("Testing case where previous == temp is true")
    // {
    //     DSAvlTree<int, int> test2;
    //     test2.insert(6, 900);
    //     std::vector<int> results = test2.contains(6);
    //     test2.insert(4, 4);
    //     results = test2.contains(4);
    //     test2.insert(7, 0);
    //     results = test2.contains(7);
    //     test2.insert(2, 2233);
    //     results = test2.contains(2);
    //     test2.insert(5, 1000000);
    //     results = test2.contains(5);
    //     REQUIRE(results.size() == 1);
    // }

    // SECTION("Testing case where previous == temp is false")
    // {
    //     DSAvlTree<std::string, int> test1;
    //     std::vector<int> results2;
    //     test1.insert("HELLOOO", 3);
    //     results2 = test1.contains("HELLOOO");
    //     test1.insert("hi", 0);
    //     results2 = test1.contains("hi");
    //     test1.insert("HOLA", 4);
    //     results2 = test1.contains("HOLA");
    //     test1.insert("heyyyy", 9000);
    //     results2 = test1.contains("heyyyy");
    //     test1.insert("hello", 1000000);
    //     results2 = test1.contains("hello");
    //     test1.insert("idk", 1);
    //     results2 = test1.contains("idk");
    //     REQUIRE(results2.size() == 1);
    //     test1.remove("hello");
    //     results2.pop_back();
    //     REQUIRE(test1.contains("hello") == std::vector<int>());
    // }
}