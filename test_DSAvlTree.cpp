#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSAvlTree.h"

// TEST_CASE("contains", "[DSAvlTree]")
// {
//     DSAvlTree<std::string> test1;
//     test1.insert("HELLOO!");
//     test1.insert("hi");
//     REQUIRE(test1.contains("hi") == true);
//     test1.remove("hi");
//     REQUIRE(test1.contains("hi") == false);
//     REQUIRE(test1.contains("HELLOO!") == true);
    
//     DSAvlTree<int> test2;
//     REQUIRE(test2.contains(0000000) == false);
//     test2.insert(-100000);
//     test2.insert(0);
//     REQUIRE(test2.contains(-100000) == true);
//     test2.remove(-100000);
//     REQUIRE(test2.contains(-100000) == false);

//     DSAvlTree<char> test3;
//     test3.insert('a');
//     test3.insert('=');
//     REQUIRE(test3.contains('a') == true);
//     REQUIRE(test3.contains('=') == true);
// }

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

TEST_CASE("makeEmpty", "[DSAvlTree]")
{
    DSAvlTree<std::string> test1;
    test1.insert("HELLOOO");
    test1.insert("hi");
    test1.insert("HOLA");
    test1.insert("heyyyy");
    test1.insert("hello");
    test1.insert("idk");
    test1.remove("hi");
    test1.insert("HELLOOO");
    test1.makeEmpty();
    REQUIRE(test1.isEmpty() == true);
    
    DSAvlTree<int> test2;
    test2.insert(0);
    test2.insert(100000000);
    test2.insert(-1000000);
    test2.insert(8402489);
    test2.insert(1);
    test2.remove(0);
    test2.insert(10090844);
    test2.insert(-47920298);
    test2.insert(244824082);
    test2.insert(-244808420);
    test2.makeEmpty();
    REQUIRE(test2.isEmpty() == true);

    DSAvlTree<char> test3; 
    test3.insert('a');
    test3.insert('!');
    test3.insert('=');
    test3.insert('_');
    test3.insert('?');
    test3.insert('*');
    test3.insert('&');
    test3.insert('b');
    test3.remove('a');
    test3.makeEmpty();
    REQUIRE(test3.isEmpty() == true);
}

TEST_CASE("public insert", "[DSAvlTree]")
{
    DSAvlTree<std::string> test1;
    test1.insert("HELLOOOO");
    //REQUIRE(test1.contains("HELLOOOO") == true);
    test1.insert("hiiiiiiiiiiiiii");
    //REQUIRE(test1.contains("hiiiiiiiiiiiiii") == true);
    
    DSAvlTree<int> test2;
    test2.insert(-1000000000);
    //REQUIRE(test2.contains(-1000000000) == true);
    test2.insert(0);
    //REQUIRE(test2.contains(0) == true);

    DSAvlTree<char> test3;
    test3.insert('a');
    //REQUIRE(test3.contains('a') == true);
    test3.insert('!');
    //REQUIRE(test3.contains('!') == true);
}

TEST_CASE("public remove", "[DSAvlTree]")
{
    DSAvlTree<std::string> test1;
    test1.insert("HELLOOOO");
    //REQUIRE(test1.contains("HELLOOOO") == true);
    test1.remove("HELLOOOO");
    //REQUIRE(test1.contains("HELLOOOO") == false);
    test1.insert("hiiiiiiiiiiiiii");
    //REQUIRE(test1.contains("hiiiiiiiiiiiiii") == true);
    test1.remove("hiiiiiiiiiiiiii");
    //REQUIRE(test1.contains("hiiiiiiiiiiiiii") == false);
    
    DSAvlTree<int> test2;
    test2.insert(-1000000000);
    //REQUIRE(test2.contains(-1000000000) == true);
    test2.remove(-1000000000);
    //REQUIRE(test2.contains(-1000000000) == false);
    test2.insert(0);
    //REQUIRE(test2.contains(0) == true);
    test2.remove(0);
    //REQUIRE(test2.contains(0) == false);

    DSAvlTree<char> test3;
    test3.insert('a');
    //REQUIRE(test3.contains('a') == true);
    test3.remove('a');
    //REQUIRE(test3.contains('a') == false);
    test3.insert('!');
    //REQUIRE(test3.contains('!') == true);
    test3.remove('!');
    //REQUIRE(test3.contains('!') == false);
}