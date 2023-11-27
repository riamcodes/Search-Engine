#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <iostream>
#include <cstdio>
#include <chrono>
#include "QueryProcessor.h"
#include "IndexHandler.h"
#include "DocumentParser.h"

class UserInterface
{
private:
    int numberOfArticles; // This integer keeps track of the total number of articles in the current index
    int totalNodes; // This integer keeps track of the total number of nodes (unique words) in the AVL tree
    IndexHandler *indexObject; // This is an object of the IndexHandler
public:
    std::string answer;  // answer to first question
    std::string answer1; // possible answer to second question
    std::string answer2; // possible answer to second question
    std::string answer3; // possible answer to second question
    UserInterface(); // Default constructor
    ~UserInterface(); // Destructor
    UserInterface(const UserInterface &rhs); // Copy Constructor
    UserInterface &operator=(const UserInterface &rhs); // Assignment Operator
    void initialQuestion(); // Asks the initial question
    void secondQuestion(); // Asks the second question
};
#endif