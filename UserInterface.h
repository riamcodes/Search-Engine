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
    std::chrono::duration<double> elapsedTrain;
    IndexHandler *ih = new IndexHandler();
    QueryProcessor qp;
    DocumentParser dp;
    // int numberOfArticles; // This integer keeps track of the total number of articles in the current index
    // int totalNodes; // This integer keeps track of the total number of nodes (unique words) in the AVL tree
public:
    void initialQuestion(); // Asks the initial question
                            // std::string answer;  // answer to first question
                            // std::string answer1; // possible answer to second question
                            // std::string answer2; // possible answer to second question
                            // std::string answer3; // possible answer to second question
                            // void secondQuestion(); // Asks the second question
};
#endif

// UserInterface(); // Default constructor
// ~UserInterface(); // Destructor
// UserInterface(const UserInterface &rhs); // Copy Constructor
// UserInterface &operator=(const UserInterface &rhs); // Assignment Operator