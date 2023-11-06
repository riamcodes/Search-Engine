#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include "UserInterface.h"

class QueryProcessor
{
private:

public:
// This function will process the answer from user interface and 
// determine how to handle it
void processingQuery();
// This function will determine the relevancy of the term(s) that it entered
// hint: use tf/idf statistic
void relevancy();
// This function will print out the relevant articles
void print();
};
#endif