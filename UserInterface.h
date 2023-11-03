#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <iostream>
#include <chrono>
#include <ctime>

class UserInterface
{
private:
    std::string answer1;

public:
    void printInitialQuestion();
    void directAnswer();
};
#endif