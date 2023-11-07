#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <iostream>
#include <chrono>
#include <ctime>
#include "QueryProcessor.h"
#include "IndexHandler.h"


class UserInterface
{
private:
    // This integer keeps track of the total number of articles in the 
    // current index
    int numberOfArticles;
    // This integer keeps track of the total number of nodes in the
    // AVL tree (total number of unique words indexed)
    int totalNodes;
    IndexHandler* indexObject;

public:
    // This string is the user's answer
    std::string answer;
    std::string answer1;
    std::string answer2;
    std::string answer3;
    // This function will ask the user a question 
    void initialQuestion();
    // This function will ask the user another question
    void secondQuestion();
    // This function will direct the answer to the correct function
    // void directAnswer();
    // This function will be responsible for timing indexing and queries
    // void time();
    // rule of 3
    // default constructor
    
};
#endif