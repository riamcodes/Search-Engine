#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class QueryProcessor
{
private:
// tf = nWordDoc/nDoc
int tf;
// idf = log2(n/nWord)
int idf;
// tf - idf = (tf)(idf)
std::vector<std::string> orgStorage;
std::vector<std::string> personStorage;
std::vector<std::string> wordStorage;
std::vector<std::string> notStorage;
std::vector<std::string> storage;
public:
// Default Constructor
QueryProcessor();
// This function will process the answer from user interface and 
// determine how to handle it
void parsingAnswer(std::string);
// This function will disect the answer
void disectAnswer();
// This function will direct the answer
void directAnswer();
// This function will determine the relevancy of the term(s) that it entered
// hint: use tf/idf statistic
void relevancy();
// This function will print out the relevant articles
void print();
// setter function
};
#endif