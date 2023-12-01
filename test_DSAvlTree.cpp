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
    REQUIRE(results.size() == 1);
    std::map<std::string, int>::iterator it = results.find("hola");
    REQUIRE(it == results.end());
    it = results.find("hi");
    REQUIRE(it != results.end());

    DSAvlTree<int, int> test2;
    test2.insert(4, 200);
    test2.insert(50, 200);
    test2.insert(600, 200);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 1);
    std::map<int, int>::iterator it1 = results2.find(4);
    REQUIRE(it1 == results2.end());
    REQUIRE(results2[200] == 1);
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

TEST_CASE("insert", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi");
    test1.insert("HI", "hi");
    test1.insert("hola", "hi");
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 1);
    std::map<std::string, int>::iterator it = results.find("hola");
    REQUIRE(it == results.end());
    it = results.find("hi");
    REQUIRE(it != results.end());

    DSAvlTree<int, int> test2;
    test2.insert(4, 200);
    test2.insert(50, 200);
    test2.insert(600, 200);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 1);
    std::map<int, int>::iterator it1 = results2.find(4);
    REQUIRE(it1 == results2.end());
    REQUIRE(results2[200] == 1);

}

TEST_CASE("remove", "[DSAvlTree]")
{
    DSAvlTree<std::string, std::string> test1;
    test1.insert("HELLO!", "hi");
    test1.insert("HI", "hi");
    test1.insert("hola", "hi");
    std::map<std::string, int> results = test1.contains("hola");
    REQUIRE(results.size() == 1);
    std::map<std::string, int>::iterator it = results.find("hola");
    REQUIRE(it == results.end());
    it = results.find("hi");
    REQUIRE(it != results.end());
    test1.remove("hola");
    results.erase("hola");

    DSAvlTree<int, int> test2;
    test2.insert(4, 200);
    test2.insert(50, 200);
    test2.insert(600, 200);
    std::map<int, int> results2 = test2.contains(4);
    REQUIRE(results2.size() == 1);
    std::map<int, int>::iterator it1 = results2.find(4);
    REQUIRE(it1 == results2.end());
    REQUIRE(results2[200] == 1);
    // test2.remove(4);
    // results2.erase(4);
}
// TEST_CASE("Copy Constructor", "[DSAvlTree]")
// {
    // DSAvlTree<std::string, int> original;
    // original.insert("HELLO!", 4);
    // original.insert("HI", 4);
    // original.insert("hola", 4);
    // DSAvlTree<std::string, std::string> test1;
    // test1.insert("HELLO!", "hi");
    // test1.insert("HI", "hi");
    // test1.insert("hola", "hi");
    // DSAvlTree<std::string, std::string> copyTree(test1);
    // std::map<std::string, std::string> results = test1.contains("hola");
    // REQUIRE(results.size() == 1);
    // std::map<std::string, int>::iterator it = results.find("hola");
    // REQUIRE(it == results.end());
    // it = results.find("hi");
    // REQUIRE(it != results.end());


    // DSAvlTree<std::string, std::string> test1;
    // test1.insert("HELLO!", "hi");
    // test1.insert("HI", "hi");
    // test1.insert("hola", "hi");
    // DSAvlTree<std::string, std::string> copyTree(test1);
    // std::map<std::string, int> results = test1.contains("hola");
    // REQUIRE(results.size() == 1);
    // std::map<std::string, int>::iterator it = results.find("hola");
    // REQUIRE(it == results.end());
    // it = results.find("hi");
    // REQUIRE(it != results.end());
    // std::map<std::string, int> results1 = copyTree.contains("hola");
    // REQUIRE(results1.size() == 1);
    // std::map<std::string, int>::iterator it1 = results1.find("hola");
    // REQUIRE(it1 == results1.end());
    // it1 = results1.find("hi");
    // REQUIRE(it1 != results1.end());


// DSAvlTree<std::string, std::string> test1;
// test1.insert("HELLO!", "hi");
// test1.insert("HI", "hi");
// test1.insert("hola", "hi");

// DSAvlTree<std::string, std::string> copyTree(test1);

// std::map<std::string, int> results1 = copyTree.contains("hola");

// // Log the contents of results1
// std::cout << "Contents of results1: ";
// for (const auto& entry : results1) {
//     std::cout << "(" << entry.first << ", " << entry.second << ") ";
// }
// std::cout << std::endl;

// REQUIRE(results1.size() == 1);

// TEST_CASE("Copy Constructor Test", "[DSAvlTree]") {
//     // Create an original tree
//     DSAvlTree<std::string, std::string> originalTree;
//     originalTree.insert("HELLO!", "hi");
//     originalTree.insert("HI", "hi");
//     originalTree.insert("hola", "hi");

//     // Create a copy using the copy constructor
//     DSAvlTree<std::string, std::string> copyTree(originalTree);

//     // Check that the two trees are not the same object
//     REQUIRE(&originalTree != &copyTree);

//     // Check that the copy is a deep copy by comparing the contents
//     REQUIRE(originalTree.contains("HELLO!"));
//     REQUIRE(originalTree.contains("HI"));
//     REQUIRE(originalTree.contains("hola"));

//     REQUIRE(copyTree.contains("HELLO!"));
//     REQUIRE(copyTree.contains("HI"));
//     REQUIRE(copyTree.contains("hola"));

//     // Modify the original tree to ensure changes don't affect the copy
//     originalTree.insert("new_key", "new_value");

//     // Check that the modified key is in the original tree but not in the copy
//     REQUIRE(originalTree.contains("new_key"));
//     REQUIRE_FALSE(copyTree.contains("new_key"));
// }

    // DSAvlTree<std::string, int> copy(original);
    

    // REQUIRE(copy.contains("HELLO!").size() == 1);
    // REQUIRE(copy.contains("HI").size() == 1);
    // REQUIRE(copy.contains("hola").size() == 1);

//     copy.remove("HELLO!");

//     REQUIRE(original.contains("HELLO!").size() == 1);
//     REQUIRE(copy.contains("HELLO!").size() == 0);
//}

// TEST_CASE("Assignment Operator", "[DSAvlTree]")
// {
//     DSAvlTree<std::string, int> original;
//     original.insert("HELLO!", 4);
//     original.insert("HI", 4);
//     original.insert("hola", 4);

//     DSAvlTree<std::string, int> copy;
//     copy.insert("bye", 10);

//     copy = original;

//     REQUIRE(copy.contains("HELLO!").size() == 1);
//     REQUIRE(copy.contains("HI").size() == 1);
//     REQUIRE(copy.contains("hola").size() == 1);

//     copy.remove("HELLO!");

//     REQUIRE(original.contains("HELLO!").size() == 1);
//     REQUIRE(copy.contains("HELLO!").size() == 0);
// }