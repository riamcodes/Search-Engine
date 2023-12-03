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
    IndexHandler ih;
    QueryProcessor qp;
    DocumentParser dp;
public:
    void initialQuestion(); // Asks the initial question
};
#endif