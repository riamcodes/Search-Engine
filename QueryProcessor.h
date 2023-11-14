#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class QueryProcessor
{
private:
// int totalDocs
// int tf; // tf = nWordDoc/nDoc
// int idf; // idf = log2(n/nWord)
// tf - idf = (tf)(idf)
std::vector<std::string> storage;
std::vector<pair<char,int>> relevantDocuments; //documents
IndexHandler *indexObject;
public:
QueryProcessor(); // Default Constructor
std::vector<document> parsingAnswer(std::string); // This function will process the answer from the user interface
void disectAnswer(); // This function will disect the answer and find it's relevant documents
void relevancy(); // This function will determine the relevancy of the term(s) that it entered (hint: use tf/idf statistics)
void intersection(); // Helper function
void complement(); // Helper function
void revelvency();
void setIndexHandler(*indexObject);
};
#endif