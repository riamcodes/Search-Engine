#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "IndexHandler.h"

class QueryProcessor
{
private:
    // int totalDocs
    // int tf; // tf = nWordDoc/nDoc
    // int idf; // idf = log2(n/nWord)
    // tf - idf = (tf)(idf)
    std::vector<std::string> storage;
    std::vector<std::pair<char, int>> relevantDocuments; 
    IndexHandler *indexObject;

public:
    QueryProcessor(); 
    std::vector<document> parsingAnswer(std::string); 
    void disectAnswer();
    void relevancy(); 
    std::vector<std::pair<document, int>> intersection(std::vector<std::pair<char, int>>, std::vector<std::pair<char, int>>); 
    std::vector<std::pair<document, int>> complement(std::vector<std::pair<char, int>>, std::vector<std::pair<char, int>>); 
    void relevency(std::vector<document>);
    void setIndexHandler(IndexHandler *indexObject);
};
#endif