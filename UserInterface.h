#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <iostream>
#include "QueryProcessor.h"
#include "IndexHandler.h"

class UserInterface
{
private:
    // This integer keeps track of the total number of articles in the current index
    int numberOfArticles;
    // This integer keeps track of the total number of nodes (unique words) in the AVL tree
    int totalNodes;
    IndexHandler *indexObject;

public:
    std::string answer;  // answer to first question
    std::string answer1; // possible answer to second question
    std::string answer2; // possible answer to second question
    std::string answer3; // possible answer to second question
    UserInterface();
    ~UserInterface();
    UserInterface(const UserInterface &rhs);
    UserInterface &operator=(const UserInterface &rhs);
    void initialQuestion();
    void secondQuestion();
};
#endif