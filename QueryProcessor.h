#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class QueryProcessor
{
private:
std::vector<std::string> storage;
public:
// This function will process the answer from user interface and 
// determine how to handle it
void parsingAnswer(std::string);
// This function will direct the answer
void directAnswer();
// This function will determine the relevancy of the term(s) that it entered
// hint: use tf/idf statistic
void relevancy();
// This function will print out the relevant articles
void print();
};
#endif