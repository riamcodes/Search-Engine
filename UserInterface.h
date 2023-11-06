#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <iostream>
#include <chrono>
#include <ctime>

class UserInterface
{
private:
    // This integer keeps track of the total number of articles in the 
    // current index
    int numberOfArticles;
    // This integer keeps track of the total number of nodes in the
    // AVL tree (total number of unique words indexed)
    int totalNodes;

public:
    // This string is the user's answer
    std::string answer1;
    // This function will ask the user a question and ask for their answer
    void printInitialQuestion();
    // This function will direct the answer to the correct function
    void directAnswer();
    // This function will be responsible for timing indexing and queries
    void time();
};
#endif